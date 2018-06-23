# Greedy

0. Often greedy insight is hard to prove upfront. In this case, you can just jump in and start implementation on condition that pause and pull back immediately when the mental picture changes/becomes clearer/more unclear! 

1. To find globally optimal value: 

	a. relaxation: start with trivial/base case, update the scope, and update the new optimal value within the scope.

	b. guess a bound based on coarse-grained proof, and later show that it is always achievable 

3. One way to prove greedy is that each change toward the greedy solution only improves the final score, until we converge to the greedy version we claim. This "gradual" improvement pattern can be seen in a lot non-greedy problems as well,i.e., iterative methods

4. Since greedy solution, by nature, is "optimal" and closely associated withe extreme value, we can add even more extreme values, e.g., the extreme case of all optimal solutions, or globally optimal instead of locally optimal. The intention is that the addition of this extreme case, introduces additional condictions which makes proof and code easier by limiting all possible options to only 1

5. Another common insight is to preserve the flexibility, pick the one most/least flexible in terms of interacting with future steps if such interaction can ever happen, otherwise, we just need to show current interactive already gives us the best
