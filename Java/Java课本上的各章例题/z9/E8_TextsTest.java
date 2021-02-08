package z9;
import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
public class E8_TextsTest {
	JFrame f = null; 
	private JPasswordField pwdIn;
	private JTextField pwdOut;
	private JTextArea pwdShow;
	E8_TextsTest(){
		f = new JFrame("JTextField、JPasswordField和JTextArea测试"); 		
		FlowLayout l=new FlowLayout(); 
        f.setLayout(l);
        Container cp = f.getContentPane();//获得放置组件的容器对象               
        pwdIn = new JPasswordField(12);       
        pwdIn.setEchoChar('#');
        pwdOut = new JTextField(12);
        pwdShow = new JTextArea(5, 12);
        pwdShow.setLineWrap(true);       
        cp.add(new JLabel("输入密码："));
        cp.add(pwdIn);
        cp.add(new JLabel("显示密码："));
        cp.add(pwdOut);
        cp.add(new JLabel("密码添加："));
        cp.add(pwdShow);
        pwdIn.addCaretListener(new CaretListener() {
        	public void caretUpdate(CaretEvent e){
        		String password = String.valueOf(pwdIn.getPassword());
        		//如果密码框改变内容，就即时更新文本框和编辑框中显示的内容    	    
        		pwdOut.setText(password);
        		pwdShow.setText(password);
        	}
        });        
        f.setSize(230, 200);
        f.setLocationRelativeTo(null);  //让窗体居中显示
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		
	}
	public static void main(String[] args) {
		new E8_TextsTest();
	}
}