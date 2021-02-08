import java.io.*;
public class test{
	public static void main(String[] args){
		try{
			BufferedReader is=new BufferedReader(new InputStreamReader(System.in));
			String inputLine;
			while((inputLine=is.readLine())!=null){
				System.out.println(inputLine);
			}
			is.close();
		}catch(IOException e){
			System.out.println("IOException:"+e);
		}
	}
}
