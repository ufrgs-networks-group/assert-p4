error { NoError, PacketTooShort, NoMatch, EmptyStack, FullStack, OverwritingHeader, HeaderTooShort, ParserTimeout }
extern packet_in<> {
  void extract<T>(out T hdr);
  void extract<T>(out T variableSizeHeader, in bit<32> variableFieldSizeInBits);
  T lookahead<T>();
  void advance<>(in bit<32> sizeInBits);
  bit<32> length<>(); }
extern packet_out<> {
  void emit<T>(in T hdr); }
match_kind { exact, ternary, lpm }
extern CounterArray<> {
  <null> CounterArray<>( bit<32> max_index,  bool sparse);
  void increment<>(in bit<32> index); }
extern array_table<> {
  <null> array_table<>( bit<32> size); }
extern hash_table<> {
  <null> hash_table<>( bit<32> size); }
parser parse<H>( packet_in packet, out H headers);
control filter<H>(inout H headers, out bool accept);
package ebpfFilter<H>( parse<H> prs,  filter<H> filt);
<Type_Typedef>(210)
<Type_Typedef>(219)
header Ethernet_h {
  EthernetAddress dstAddr;
  EthernetAddress srcAddr;
  bit<16> etherType; }
header IPv4_h {
  bit<4> version;
  bit<4> ihl;
  bit<8> diffserv;
  bit<16> totalLen;
  bit<16> identification;
  bit<3> flags;
  bit<13> fragOffset;
  bit<8> ttl;
  bit<8> protocol;
  bit<16> hdrChecksum;
  IPv4Address srcAddr;
  IPv4Address dstAddr; }
struct Headers_t {
  Ethernet_h ethernet;
  IPv4_h ipv4; }
parser prs() {
  state start {
    p.extract<Ethernet_h>(headers.ethernet);
    select{headers.ethernet.etherType} {
      2048: ip
      default: reject } }
  state ip {
    p.extract<IPv4_h>(headers.ipv4);
    accept; }
  state accept { }
  state reject { } }
control pipe() {
  @name("counters") CounterArray counters(10, 1)
  action act() {
    counters.increment((bit<32>)headers.ipv4.dstAddr);
    pass = 1; }
  action act_0() {
    pass = 0; }
  table tbl_act() {
    actions = { act(); }
    const default_action = act(); }
  table tbl_act_0() {
    actions = { act_0(); }
    const default_action = act_0(); }
  if (headers.ipv4.isValid()) {
    { tbl_act.apply(); }
  } else {
    tbl_act_0.apply(); } }
ebpfFilter<Headers_t> main(prs(), pipe())
