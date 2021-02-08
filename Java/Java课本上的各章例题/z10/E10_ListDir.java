package z10;
import java.io.File;
public class E10_ListDir {
	public static void main(String[] args) {
		File f =new File("./z10");
        listDir(f);
	}
	public static void listDir(File mydir){
        System.out.println("目录：" + mydir);
        File[] files =mydir.listFiles();
        for(File f:files){
            if(f.isDirectory()) listDir(f);
            else System.out.println("文件：" + f);
        }
    }
}