import java.io.*;
public class BufferedReaderTest{
	public static void main(String[] args){
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=null;
		while(true){
			try{
				str=br.readLine();
			}catch(IOException e){
				e.printStackTrace();
			}
			if(str.equals("END"))
				break;
			System.out.println(str);
		}
	}
}

/*
请注意：

(1）read方法：读取单个字符。 返回：作为一个整数（其范围从 0 到 65535 
(0x00-0xffff)）读入的字符，如果已到达流末尾，则返回 -1 ；

(2)readLine方法：读取一个文本行。通过下列字符之一即可认为某行已终止：
换行 ('\n')、回车 ('\r') 或回车后直接跟着换行。 返回：包含该行内容的
字符串，不包含任何行终止符，如果已到达流末尾，则返回 null。

 */