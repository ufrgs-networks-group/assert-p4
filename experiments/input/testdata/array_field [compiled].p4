header H {
  bit<1> z; }
bit<1> f<>(inout bit<1> x, in bit<1> b)
control c<>(out H[2] h);
package top<>( c _c);
control my() {
  bit<32> a
  bit<32> tmp_8
  bit<32> tmp_9
  bit<32> tmp_10
  bit<32> tmp_11
  bit<1> tmp_12
  bit<1> tmp_13
  bit<32> tmp_14
  bit<1> tmp_15
  bit<1> tmp_16
  action act() {
    a = 0;
    tmp_8 = a;
    s[tmp_8].z = 1;
    tmp_9 = a + 1;
    tmp_10 = tmp_9;
    s[tmp_10].z = 0;
    tmp_11 = a;
    tmp_12 = s[tmp_11].z;
    tmp_13 = f(tmp_12, 0);
    s[tmp_11].z = tmp_12;
    a = (bit<32>)tmp_13;
    tmp_14 = a;
    tmp_15 = s[tmp_14].z;
    tmp_16 = f(tmp_15, 1);
    s[tmp_14].z = tmp_15; }
  table tbl_act() {
    actions = { act(); }
    const default_action = act(); }
  tbl_act.apply(); }
top main(my())
