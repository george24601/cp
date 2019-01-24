T(n) =  a * T(n/b) + f(n)

Crititcal component: f(n) is relation simple with log(a)/log(b), relative size of number of subproblems vs size of a single sumproblem

* Subproblem itself is more expensive than splitting and re-combining problem it self, i.e. f(n) < O( n^(log(a)/log(b))) 
  * then T(n) = Theta(n^(log(a)/log(b))), i.e., dominated by the leaf level subproblem
  * Theta(n) means it is O(n) and Gamma(n)
* Subproblem itself is much less than splitting and re-combining problem itself,i.e., f(n) > Gamma(n^(log(a)/log(b))), AND a * f(n / b) < f(n), then it is Theta(f(n)). 
  * Note without the AND condition we can not conclude too much here! 
* Otherwise, BOTH subproblem AND spliting/re-combining state must be considered, i.e., f(n) = Theta(n^(log(a)/log(b)) * log(n) ^k) k >= 0, then T(n) = Theta(n^(log(a)/log(b)) * log(n)^(k+1))

### Proof

* log(n)/log(b) levels, at each level i, there are a^i subproblems with size n/(b^i), the splitting and re-combing at this leve, thus takes f(n/(b^i))  * a^i, 
* Assuming f(n) = n^c, then at level i, the total overhead is n^c * (a/b^c)^i, i.e., the overall cost, sum of geometrics series totally depend on the factor i.e. (a/b^c) , when the factor < 1, i.e., c > log(a)/log(b), we know it is dominated by the first level f(n) = O(n^log(a)/log(b))


### Examples

* Binary search
* Biary tree traversal
* Merge sort
