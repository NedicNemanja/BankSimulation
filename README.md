# BankSimulation

Bank queue simulation with randomized customer arrival probability and a clerk policy. Implemented for the undergrad class of Data Structures.

# Run example
```
Input:
Arrival probability for a customer [0,1]
Max service time (unsigned int >= 1min)
Operating time of the bank (unsgined int >= 0min)
0.9
3
30

Served 26 customers.
0 customers were not served.
Average wait time was 0.77 min.
Bank worked for 31 min.
The bank worked 1 min overtime

 Clerk1:
	 Served 13 customers
	 Was occupied for 31 min
	 Was inactive for 0 min
	 Worked 1 min overtime

 Clerk2:
	 Served 13 customers
	 Was occupied for 27 min
	 Was inactive for 3 min
	 Worked 0 min overtime
```
If you wish to change the num of clerks change the
```include/Clerk.h:10 #define TAMIES 2``` 
to whatever you want.
