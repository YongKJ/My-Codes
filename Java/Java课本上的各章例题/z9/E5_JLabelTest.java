package z9;
import java.awt.*;
import javax.swing.*;
public class E5_JLabelTest {
	JFrame jf = new JFrame("标签JLabel测试");
	Container cp = jf.getContentPane();
	E5_JLabelTest(){
		JLabel l1 = new JLabel("韶关旅游图",new ImageIcon("z8\\Z8_2_SGly1.gif"),JLabel.RIGHT);
		cp.add(l1);		
		l1.setHorizontalTextPosition(JLabel.CENTER); //文本水平中间对齐
		l1.setVerticalTextPosition(JLabel.TOP);//垂直上面对齐
		l1.setForeground(Color.red); //标签前景色
		l1.setBackground(Color.blue);//标签背景色
		l1.setFont(new Font("宋体",Font.BOLD,20));
		jf.pack();
		jf.setVisible(true);;
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//用户点击窗口关闭  		
	}	
	public static void main(String[] args) {
		new E5_JLabelTest();
	}
}