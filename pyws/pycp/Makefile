M := cp
F := A_1.in
l: 
	yapf -i --style=google $(M).py 
	
r: l
	python3 $(M).py < A_1.in
r2: l
	./wordcount.py --topcount $(F)

