extern e<T> {
  <null> e<>();
  T get<>(); }
parser simple<>(out bit<2> a);
package m<>( simple n);
parser p1_0() {
  bit<2> tmp_0
  @name("ei") e<bit<2>> ei()
  state start {
    tmp_0 = ei.get();
    a = tmp_0;
    accept; }
  state accept { }
  state reject { } }
m main(p1_0())
