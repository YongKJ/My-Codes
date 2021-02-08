package z8;
import java.awt.*;
import javax.swing.*;
public class E5_FlowLayoutTest {
	JFrame f;
	E5_FlowLayoutTest() {
		f = new JFrame("FlowLayout测试");
		FlowLayout fl = new FlowLayout(FlowLayout.RIGHT,10,10);
		f.setLayout(fl);
		f.add(new JButton("短按钮"));
		f.add(new JButton("中间长度按钮"));
		f.add(new JButton("比较长一点的按钮"));
		f.add(new JButton("四个按钮中最长的一个按钮"));
		f.setSize(300, 200);
		f.setVisible(true);
		f.setLocationRelativeTo(null);  //让窗体居中显示
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//用户点击窗口关闭  
	}
	public static void main(String[] args) {
		new E5_FlowLayoutTest();
	}
}