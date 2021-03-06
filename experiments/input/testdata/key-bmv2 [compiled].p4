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
match_kind { range, selector }
struct standard_metadata_t {
  bit<9> ingress_port;
  bit<9> egress_spec;
  bit<9> egress_port;
  bit<32> clone_spec;
  bit<32> instance_type;
  bit<1> drop;
  bit<16> recirculate_port;
  bit<32> packet_length; }
extern Checksum16<> {
  <null> Checksum16<>();
  bit<16> get<D>(in D data); }
<Type_Enum>(167)
extern counter<> {
  <null> counter<>( bit<32> size,  CounterType type);
  void count<>(in bit<32> index); }
extern direct_counter<> {
  <null> direct_counter<>( CounterType type); }
extern meter<> {
  <null> meter<>( bit<32> size,  CounterType type);
  void execute_meter<T>(in bit<32> index, out T result); }
extern direct_meter<T> {
  <null> direct_meter<>( CounterType type);
  void read<>(out T result); }
extern register<T> {
  <null> register<>( bit<32> size);
  void read<>(out T result, in bit<32> index);
  void write<>(in bit<32> index, in T value); }
extern action_profile<> {
  <null> action_profile<>( bit<32> size); }
<Type_Enum>(350)
extern action_selector<> {
  <null> action_selector<>( HashAlgorithm algorithm,  bit<32> size,  bit<32> outputWidth); }
parser Parser<H, M>( packet_in b, out H parsedHdr, inout M meta, inout standard_metadata_t standard_metadata);
control VerifyChecksum<H, M>(in H hdr, inout M meta);
control Ingress<H, M>(inout H hdr, inout M meta, inout standard_metadata_t standard_metadata);
control Egress<H, M>(inout H hdr, inout M meta, inout standard_metadata_t standard_metadata);
control ComputeChecksum<H, M>(inout H hdr, inout M meta);
control Deparser<H>( packet_out b, in H hdr);
package V1Switch<H, M>( Parser<H, M> p,  VerifyChecksum<H, M> vr,  Ingress<H, M> ig,  Egress<H, M> eg,  ComputeChecksum<H, M> ck,  Deparser<H> dep);
header hdr {
  bit<32> a;
  bit<32> b; }
struct Headers {
  hdr h; }
struct Meta { }
parser p() {
  state start {
    b.extract<hdr>(h.h);
    accept; }
  state accept { }
  state reject { } }
control vrfy() { }
control update() { }
control egress() { }
control deparser() {
  b.emit<hdr>(h.h); }
control ingress() {
  bit<32> key_0
  action NoAction_0/NoAction_1() { }
  action c_a/c_a_0() {
    h.h.b = h.h.a; }
  table c_t_0/c_t() @name("c.t") {
    key = { @name("e") key_0: exact; }
    actions = { c_a/c_a_0();
      NoAction_0/NoAction_1(); }
    default_action = NoAction_0/NoAction_1(); }
  action act() {
    key_0 = h.h.a + h.h.a; }
  action act_0() {
    sm.egress_spec = 0; }
  table tbl_act() {
    actions = { act(); }
    const default_action = act(); }
  table tbl_act_0() {
    actions = { act_0(); }
    const default_action = act_0(); }
  tbl_act.apply();
  c_t_0/c_t.apply();
  tbl_act_0.apply(); }
V1Switch<Headers, Meta> main(p(), vrfy(), ingress(), egress(), update(), deparser())
