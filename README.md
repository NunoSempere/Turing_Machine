I asked my programming teacher how to create a Turing Machine that reaches the nth prime.

He thought I was joking.
He was WRONG.

I never make jokes :)

Anyways, to grok how Turing machines, as described in Automata and Computability, by Dexter C. Kozen, work, here are:
- A Turing Machine that accepts if a number n doesn't divide another number m and rejects otherwise.
- A Turing Machine that accepts if n doesn't divide m, or if n=m, and rejects otherwise.
- A Turing Machine that accepts if n is prime, and rejects otherwise.
- A Turing Machine that accepts once it has found the nth prime.

Early versions, deprecated, start with 0.
- A Turing Machine that accepts if a number n doesn't divide another number m and rejects otherwise.
- A Turing Machine that detects whether a number >=2 is prime.

Here is a walkthrough of how the TMs work. The states are gradually defined as the Turing machine moves, and then modified when it makes sense to do so. I think that this will be easier to understand than a table.

(divisor 1.0) Accepts if n doesn't divide m, rejects otherwise.

Gets as an input 0111...11822..229␣␣␣␣␣...., where:

- 0 is the left endmarker
- There are (n-1) '1's, and 1 '8'. The 8 signals the end of the '1's.
- Similarly, there are (m-2) '2's and 1 '9'. The 9 signals the end of the '2's.
- The ␣ are empty characters, and the TM has an infinite number of them to the left.

state 0:
- The TM starts on this state.
- Inmediatly, it moves to the right, to state 1.

state 1:
- Looks for a 1 to replace by a three
- if symbol = 1, write 3, move to the right, change to state 2.
- otherwise: move to the right, keep state.

state 2:
- it looks for a 2 to replace by a 4.
- if symbol = 2, write 4, change to state 3.
- else: move to the right, keep state

state 3:
- if it doesn't find a 0, go to the left, keep state
- if it finds a 0, write 0, move to the right, go to state 1.

// As I write this, I realize that if I replace state 0 by state 3, nothing happens.

// Excursus: After competing this project, I searched for similar ones, and found one by a William Bernoudy. My finding the nth prime TM had 14 states and 12 symbols, while his had 14 states and only 10 symbols. But if I replace state 0 by state 3, I have one state less! Anyways, from now on no state is state 3.

state 0:
- If symbol = 0, go to state 1.
- Else: move to the right, keep state.

Now, once all the 1s are turned into 3s, state 1 would go on searching, so we want to modify it to notice that it has run out of threes.

state 1:
- if symbol = 1, write 3, move to the right, change to state 2.
- if symbol = 8, write 8, move to the right, change to state 4.
- otherwise: move to the right.

If there were no 2s left to turn to 4s, then n|m (n divides m). But if there are, n can still divide m, so we keep on going.

state 4:
- if symbol = 2, write 4, move to the right, change to state 5.
- if symbol = 9, REJECT, n | m

We also notice that if state 2 finds no 2s to turn into 4s, then ¬ (n|m), so we add that option.

state 2:
- if symbol = 2, write 4, change to state 3.
- if symbol = 9, ACCEPT.
- else: move to the right.

If state 4 does find a 2, then the situation looks, for example, like this; take n=3, m=6, then the tape cpuld have:

0338444229

3 '2's were turned into '4's. and we are in state 5, which turns the '3's into '1's and keeps going

state 5:
- if symbol = 3, write 1, move to the left, keep state.
- if symbol = 0, write 0, move to the right, change to state 1.
- else: move to the left, keep state.

End.

(divisor 1.1) Accepts if n|m or if n=m.

Now the input is: 05111...11822..229
The 5 will be to a 6 once we change the 2 that corresponds to the 8. If there is no such 2, n = m.
So we modify state 4 and 5 and create a state 6.

state 5:
- if it reads a 3, write 1, move left, keep state.
- if it reads a 5, write 6, keep state. // It has found such a 2.
- if it reads a 0, write 0, change to state 1.

state 4:
- if it reads a 2, write 4, move to the left, change to state 5
- if it reads a 9, write 9, move to the left, change to state 6.
- else: move to the right, keep state.

state 6:
- if it reads a 5, accept.
- if it erads a 6, reject.
- else: move to the left.

