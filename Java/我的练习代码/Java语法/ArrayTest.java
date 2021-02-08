public class ArrayTest{
	public static void main(String[] args){
		//(动态)
		int a[];
		a=new int[3];
		for(int i=0;i<3;i++){
			a[i]=i;
		}
		for(int j:a){
			System.out.println(j);
		}
		//(静态)
		int b[]={0,1,2};
		for(int k:b){
			System.out.println(k);
		}
		
	}
}
