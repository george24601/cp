### Greedy

0. Often greedy insight is hard to prove upfront. In this case, you can just jump in and start implementation on condition that pause and pull back immediately when the mental picture changes/becomes clearer/more unclear! 
1. To find globally optimal value: 
	a. relaxation: start with trivial/base case, update the scope, and update the new optimal value within the scope.
	b. guess a bound based on coarse-grained proof, and later show that it is always achievable 
3. One way to prove greedy is that each change toward the greedy solution only improves the final score, until we converge to the greedy version we claim. This "gradual" improvement pattern can be seen in a lot non-greedy problems as well,i.e., iterative methods
4. Since greedy solution, by nature, is "optimal" and closely associated withe extreme value, we can add even more extreme values, e.g., the extreme case of all optimal solutions, or globally optimal instead of locally optimal. The intention is that the addition of this extreme case, introduces additional condictions which makes proof and code easier by limiting all possible options to only 1
### Search 

1. If the target could appear in multiple places, search all possible places. The main benefit is that it may save you some very detailed case discussion. Conversely, if you find case discussion is too annoying, just see if you can complete search the candidate space
2. If the target needs to satify multiple conditions, chop the conditions into sets independent of each other, and solve one at a time. In the end, just take the intersection of all result sets
3. Relaxation, complete search on the proprty of unknowns and proceed from there. Often, you can prove that it is actually if and only if conditions, i.e., no further step required!

