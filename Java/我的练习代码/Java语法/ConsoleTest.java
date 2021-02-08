import java.io.*;
public class ConsoleTest{
	public static void main(String[] args){
		Console console=System.console();
		if(console==null){
			throw new IllegalStateException("Console is not available!");
		}
		String str=null;
		while(true){
			str=console.readLine("请输入：");
			if("END".equals(str))
				break;
			System.out.println(str);
		}
	}
}
//使用java.io.Console