package z10;
import java.io.*;
public class E8_CharArrayReaderWriter {
	public static void main(String[] args) throws IOException {
		char[] a = "CharArrayReader and CharArrayWriter test!".toCharArray();
        CharArrayReader cr = new CharArrayReader(a);
        CharArrayWriter cw = new CharArrayWriter(); 
        PrintWriter pw = new PrintWriter(cw,true); 
        int c;
        while((c=cr.read()) != -1){
            pw.print((char)c);
        }
        pw.close();
        cw.close();
        cr.close();
        String info = cw.toString();
        System.out.println("输出信息:" + info);
	}
}