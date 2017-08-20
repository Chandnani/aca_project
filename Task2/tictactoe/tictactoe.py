import sys
def ShowBoard( a ):
	for i in range(0,9) :
		if a[i]==1:
			sys.stdout.write(" X ");
		elif a[i]==2:
			sys.stdout.write(" O ");
		else:
			sys.stdout.write("   ");
		if i%3==2 :
			sys.stdout.write("\n");
		else :
			sys.stdout.write("|");
	return
def valid( x,a ) :
	if a[x-1] == 0 :
		return True
	else :
		return False
def Check(a,x):
	r = int((x-1)/3)
	c = (x-1)%3
	if (a[3*r]==a[3*r+1])and(a[3*r]==a[3*r+2])and(a[3*r]!=0):
		return True
	if (a[c]==a[c+3])and(a[c]==a[c+6])and(a[c]!=0):
		return True
	return ((a[0]==a[4])and(a[4]==a[8])and(a[0]!=0))or((a[2]==a[4])and(a[4]==a[6])and(a[2]!=0))
def Put(a):
	for i in range(0,9) :
		if a[i]==0 :
			a[i]=2
			if Check(a,i+1)==True :
				return i+1
			else :
				a[i] = 0
	for i in range(0,9):
		if a[i]==0 :
			a[i]=1
			if Check(a,i+1)==True :
				a[i]=2
				return i+1
			else :
				a[i] = 0
	b = [0,2,6,8,4,1,3,5,7]
	for i in b :
		if a[i]==0 :
			a[i]=2
			return i+1
	

while True:
	q = input("Press any key to start the game, q to Quit program\n")
	if q=='q':
		break
	print("Let the game begin!")
	a=[0,0,0,0,0,0,0,0,0]
	win = False
	i = 0
	while win==False :
		ShowBoard(a)
		x = int(input("What is your next move? (1-9)"))
		
		while valid(x,a)==False :
			x = int(input("Invalid Move! Please make a valid move . (1-9)?"))
		a[x-1] = 1 
		ShowBoard(a)
		win = Check(a,x)
		i=i+1

		if  win==True:
			print("Congarts! You win!")
		elif i==5 :
			print("Game Draw!\n\n")
			break

		print("My Chance! Please wait...")
		x = Put(a)
		ShowBoard(a)
		print("I move at ",x)
		win = Check(a,x)
		if win ==True :
			print("Sorry you lost! Better Luck Next time! ")


