import java.io.*;
public class FileTest{
	void readInfoFromDatabase(){
		try{
			String str;  
			FileReader file = new FileReader("database.txt");
			BufferedReader reader = new BufferedReader(file);
			while ((str=reader.readLine())!=null) { 
				System.out.println(str);			
			}
			reader.close();
			file.close();
		}catch(Exception e){
			//System.out.println("Wrong!");
		}
	}
	void writeInfoToDatabase(){
		try{
			String str;
			InputStreamReader readString = new InputStreamReader(System.in);
			BufferedReader reader = new BufferedReader(readString);
			FileWriter file = new FileWriter("database1.txt");
			BufferedWriter writer=new BufferedWriter(file);
			System.out.println("请输入要保存的行，输入‘#’号结束。");
			while (!(str=reader.readLine()).equals("#")) { 
			writer.write(str + "\n");			
			}
			writer.flush();
			reader.close();
			file.close();
		}catch(Exception e){}
	}
	public static void main(String[] args){
		FileTest f=new FileTest();
		f.readInfoFromDatabase();
		System.out.println();
		f.writeInfoToDatabase();
	}
}
