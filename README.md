I asked my programming teacher how to create a Turing Machine that reaches the nth prime.

He thought I was joking.

He was wrong.

I never make jokes :)

Anyways, to see if I could do it and to grok how Turing machines work, as described in Automata and Computability, by Dexter C. Kozen, here are:
- A Turing Machine that accepts if a number n doesn't divide another number m and rejects otherwise.
- A Turing Machine that accepts if n doesn't divide m, or if n=m, and rejects otherwise.
- A Turing Machine that accepts if n is prime, and rejects otherwise.
- A Turing Machine that accepts once it has found the nth prime.

Early versions, deprecated, start with 0.
- A Turing Machine that accepts if a number n doesn't divide another number m and rejects otherwise.
- A Turing Machine that detects whether a number >=2 is prime.

Every function is my own.

If you want to see the raw functions, go to, f.ex., find_nth_prime 1.1 -> states.c You can also download any folder and, in Linux/Ubuntu, compile it with the instruction 
      gcc -g main.c turing.c states.c turing.h states.h const.h -o main
 and run it in the Linux command line with
      ./main
 To do this, you will have to be in the appropriate folder, which you can change by using the command 
      cd ./Foldername/Subfoldername/Subsubfoldername
 In Windows, compile it and run it with the compiler of your choice.
 There is also an animation at: https://www.youtube.com/watch?v=dQw4w9WgXcQ&t=42

***

Below is a transcription of my notes, which are dry but should be easy to understand. The states are gradually defined as the Turing machine moves, and then modified when it makes sense to do so. 

(divisor 1.0) Accepts if n doesn't divide m, rejects otherwise.

Gets as an input 0111...11822..229␣␣␣␣␣...., where:

- 0 is the left endmarker
- There are (n-1) '1's, and 1 '8'. The 8 signals the end of the '1's.
- Similarly, there are (m-2) '2's and 1 '9'. The 9 signals the end of the '2's.
- The ␣ are blanks, and the TM has an infinite number of them to the left.

state 0:
- The TM starts on this state.
- Inmediatly, it moves to the right, to state 1.

state 1:
- Looks for a 1 to replace by a three
- if symbol = 1, write 3, move right, change to state 2.
- otherwise: move right, keep state.

state 2:
- it looks for a 2 to replace by a 4.
- if symbol = 2, write 4, change to state 3.
- else: move right, keep state

state 3:
- if it doesn't find a 0, go to the left, keep state
- if it finds a 0, write 0, move right, go to state 1.

// As I write this, I realize that if I replace state 0 by state 3, nothing happens.

// Excursus: After competing this project, I searched for similar ones, and found one by a William Bernoudy. My finding the nth prime TM had 14 states and 12 symbols, while his had 14 states and only 10 symbols. But if I replace state 0 by state 3, I have one state less! Anyways, from now on no state is state 3. We modify state 2, which refers to it.

state 0:
- If symbol = 0, move right, change to state 1.
- else: move left, keep state.

state 2:
- it looks for a 2 to replace by a 4.
- if symbol = 2, write 4, change to state 0.
- else: move right, keep state

Now, once all the 1s are turned into 3s, state 1 would go on searching, so we want to modify it to notice that it has run out of threes.

state 1:
- if symbol = 1, write 3, move right, change to state 2.
- if symbol = 8, write 8, move right, change to state 4.
- otherwise: move right.

If there were no 2s left to turn to 4s, then n|m (n divides m). But if there are, n can still divide m, so we keep on going.

state 4:
- if symbol = 2, write 4, move to the right, change to state 5.
- if symbol = 9, REJECT, n | m

We also notice that if state 2 finds no 2s to turn into 4s, then ¬ (n|m), so we add that option.

state 2:
- if symbol = 2, write 4, change to state 0.
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
The 5 will be cahnged to a 6 once we change the 2 that corresponds to the 8. If there is no such 2, n = m. So we modify state 4 and 5 and create a state 6.

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
- if it reads a 6, reject.
- else: move to the left.

End.

(is prime 1.1) Accepts if n is prime.

We start with: 0518777...77722..229

This reads: The initial n=2, after which there are enough 7s to increase n to find divisors of m.

Q: But, how many 7s?

A: Well, a priori at least sqrt(n), but up to n, if you one.

Q: But Nuño, if you put ceil(sqrt(n)) '7's, aren't you offloading some of the calculations to yourself instead of making the machine calculate it?

A: Yes, I am.

Anyways, right now the only state which can accept is state 2, which does so if ¬(n|m) for a given n. Instead of accepting, we want to increase n by 1. We modify state 2, and create 2 new states: state 7 and state 8.

state 2:
- if it reads a 2: write 4, move left, change to state 0.
- if it reads a 9: write 9, move left, change to state 7.
- else: move to the right

state 7:
- if it reads a 6: write 5, move left, keep state.
- if it reads a 4: write 2, move left, keep state.
- if it reads a 3: write 1, move left, keep state.
- if it reads a 0: write 0, move right, change to state 8.

state 8:
-if it reads an 8: write 1, move right, keep state.
-if it reads a 7: write 8, move right, change to state 3.
- if it reads a 2: ACCEPT. There is no space left, at least one of each pair of divisors has been tried

End.

(Find the nth prime 1.1)

Initial input: 0AA...AA51829␣␣␣...␣␣

The TM will replace an A by a B each time it finds a prime, so if n-1 is the number of 'A's, it will find the nth prime.

State 9 will change an A to a B. States 10, 11  and 12 initialize n to 2. 

States 12, 13 and 14 move m one step to the right and increase it to m+1. Thus, at each step n will be bounded only by m+1.

The states that can accept are state 6 and state 8, and only state 6 can reject. We modify them so:

state 6 
- if it reads a 5, write 5, change to state 9.
- if it reads a 6: write 6, change to state 10.
- else: move to the left.

state 8:
-if it reads an 8: write 1, move right, keep state.
-if it reads a 7: write 8, move right, change to state 3.
-if it reads a 2: write 2, move left, change to state 9.

state 9:
- if it reads an A: write B, move right, change to state 10.
- if it reads a 0: ACCEPT. There are no more As to change.
- else: move left.

state 10:
- if is reads a 1: write 1, move right, change to state 11.
- if is reads a 3: write 1, move right, change to state 11.
- else: move right.

state 11:
- if it reads a 1: write 8, move right, change to state 12
- if it reads a 3: write 8, move right, change to state 12
- if it reads a X: write 8, move right, change to state 12
- else: REJECT // Shouldn't be seeing anything else.

state 12:
- if it reads a 1: write 7, move right, keep state
- if it reads a 3: write 7, move right, keep state
- if it reads a 8: write 7, move right, keep state
- if it reads a 2: write 7, move right, change to state 13.
- if it reads a 4: write 7, move right, change to state 13.
- else: move right.

state 13:
- if it reads a 9: write 2, move right, keep state
- if it reads a 4: write 2, move right, keep state
- if it reads a ␣: write 2, move right, change to state 14
- else: move right.

state 14:
- if it reads a ␣: write W, move left, change to state 0.
