package z8;
import java.awt.*;
import javax.swing.*;
public class E10_NullLayoutTest {
    JFrame jf=new JFrame("null布局测试");
	JLabel lName = new JLabel("用户名称：");
	JTextField tName = new JTextField();
	JLabel lPasswd = new JLabel("用户密码：");
	JPasswordField tPasswd = new JPasswordField();
	JButton Login = new JButton("登录");
	JButton Reset = new JButton("重设");
	E10_NullLayoutTest() {
		Container cp = jf.getContentPane();//获得放置组件的容器对象  
		jf.setLayout(null); 
		// 手工设置各个组件的位置和大小
		lName.setBounds(new Rectangle(45, 38, 67, 34));
		tName.setBounds(new Rectangle(115, 39, 210, 33));
		lPasswd.setBounds(new Rectangle(43, 86, 66, 26));
		tPasswd.setBounds(new Rectangle(115, 84, 210, 33));
		//tPasswd.setEchoChar('#');
		Login.setBounds(new Rectangle(78, 150, 86, 30));
		Reset.setBounds(new Rectangle(193, 150, 86, 30));
		cp.add(lName); 
		cp.add(tName);
		cp.add(lPasswd);
		cp.add(tPasswd);
		cp.add(Login);
		cp.add(Reset);
		jf.setSize(390, 250);        
        jf.setVisible(true);   
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//用户点击窗口关闭  
	}
	public static void main(String[] args) {
		new E10_NullLayoutTest();
	}
}