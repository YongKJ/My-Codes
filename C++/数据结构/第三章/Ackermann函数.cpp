 int Ack(int m,int n){
 	 if(m==0)
 	 	 return n+1;
 	 else if(m!=0&&n==0)
 	 	 return Ack(m-1,1);
 	 else
 	 	 return Ack(m-1,Ack(m,n-1));
 }
 
 /*
 	 Ack(2,1)的计算过程：
 	 Ack(2,1)=Ack(1,Ack(2,0))
 	 		=Ack(1,Ack(1,1)
 	 		=Ack(1,Ack(0,Ack(1,0)))
 	 		=Ack(1,Ack(0,Ack(0,1)))
 	 		=Ack(1,Ack(0,2))
 	 		=Ack(1,3)
 	 		=Ack(0,Ack(1,2))
 	 		=Ack(0,Ack(0,Ack(1,1)))
 	 		=Ack(0,Ack(0,Ack(0,Ack(1,0))))
 	 		=Ack(0,Ack(0,Ack(0,Ack(0,1))))
 	 		=Ack(0,Ack(0,Ack(0,2)))
 	 		=Ack(0,Ack(0,3))
 	 		=Ack(0,4)
 	 		=5
*/