M := cp
F := A_1.txt
l: 
	yapf -i --style=google $(M).py 
	
r: l
	python3 $(M).py < A_1.txt
r2: l
	./wordcount.py --topcount $(F)

