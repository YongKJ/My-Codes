package z10;
import java.io.*;
public class E11_RandomAccessFileTest {
	public static void main(String[] args) throws IOException {
		RandomAccessFile rf = new RandomAccessFile("z10/Z10test.dat", "rw"); 
		rf.seek(rf.length()); 
        rf.writeChars("hello world!\n");
        rf.writeBoolean(true);
        rf.writeChar('a');
        rf.writeChar('b');
        rf.writeDouble(3.1415926);              
        rf.seek(rf.length()-12); //转到a     
        System.out.println(rf.readChar());        
        rf.skipBytes(2);   //转到3.1415926 
        System.out.println(rf.readDouble());      
        rf.seek(rf.length()-13); //转到true 
        System.out.println(rf.readBoolean());
        rf.seek(rf.length()-26); //转到world! 
        System.out.println(rf.readLine());
        rf.close(); 
	}
}