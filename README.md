# Arduino-LCQmeter
Sketches for turning arduino to L- C- and Q- meter

Basic idea:
-use variations of RC and RL, next go to LC 
-use internal arduino comparator, if possible

Plan:
1. simple RC C-meter, test comparator - RC-meter-1 - OK
2. RC-meter with interrupt - RC-meter-interrupt - OK
3. RL-meter - unsuccess, need big current 
4. LC-meter with TTL mosfet - useful, but not included in final collection
5. LC-meter with internal arduino comparator. - OK, need more testing
6. RC-meter from one blog - just copy, interesting idea for picofarads measuring

next to extend LC-get to generator and Q-meter

