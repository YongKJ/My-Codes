package z8;
import java.awt.*;
import javax.swing.*;
public class E8_GridFrameTest {
	JFrame f=new JFrame("网格布局测试");
	Container cp = f.getContentPane();//获得放置组件的容器对象  
	JPanel jp=new JPanel(new GridLayout(4,4,3,3));//4行4列，组件水平和垂直间距均为3
    JTextArea ta=new JTextArea(); 
    String str[]={"1","2","3","+","4","5","6","-","7","8","9","*","0",".","=","/"};
    E8_GridFrameTest(){    	
        JButton btn[]; 
        btn=new JButton[str.length];
        for(int i=0;i<str.length;i++){
               btn[i]=new JButton(str[i]);
               jp.add(btn[i]);
        }
        cp.add(ta,BorderLayout.NORTH); 
    	cp.add(jp,BorderLayout.CENTER); 
    	f.setSize(250,200);
    	f.setLocationRelativeTo(null);//让窗体居中显示
    	f.setVisible(true);            
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
	public static void main(String[] args) {
		new E8_GridFrameTest();
	}
}