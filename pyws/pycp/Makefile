M := wordcount
F := A_1.txt
l: 
	yapf -i --style=google $(M).py 
	
r: l
	python3 $(M).py
r2: l
	./wordcount.py --topcount $(F)

