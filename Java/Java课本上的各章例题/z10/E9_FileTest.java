package z10;
import java.io.File;
public class E9_FileTest {
	public static void main(String[] args) {
		File f = new File("z10/Z10_TestData.txt");
		System.out.println("文件是否存在：" + f.exists());
		System.out.println("文件是否能读：" + f.canRead());
		System.out.println("文件是否可写：" + f.canWrite());
		System.out.println("文件是否可执行：" + f.canExecute());
		System.out.println("文件是否是隐藏文件：" + f.isHidden());
		System.out.println("文件对象是普通文件：" + f.isFile());
		System.out.println("文件对象是否是目录：" + f.isDirectory());		
		System.out.println("文件的绝对路径：" + f.getAbsolutePath());
		System.out.println("文件对象的名称：" + f);
		System.out.println("文件的所在路径：" + f.getPath());
		System.out.println("文件的父路径名：" + f.getParent());		
		System.out.println("文件的名称：" + f.getName());
		System.out.println("文件的最后修改时间：" + f.lastModified());	
		System.out.println("文件的字节数：" + f.length());		
	}
}