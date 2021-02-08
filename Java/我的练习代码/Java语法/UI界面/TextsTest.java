import java.awt.*;
import javax.swing.*;
import javax.swing.event.*;
public class TextsTest {
	private JFrame f = null; 
	private JPasswordField pwdIn;
	private JTextField pwdOut;
	private JTextArea pwdShow;
	private FlowLayout l;
	private Container cp;
	private JLabel s1,s2,s3;
	TextsTest(){
		f = new JFrame("JTextField、JPasswordField和JTextArea测试"); 		
		l=new FlowLayout(); 
        cp = f.getContentPane();//获得放置组件的容器对象               
        pwdIn = new JPasswordField(12);       
        pwdOut = new JTextField(12);
        pwdShow = new JTextArea(5, 12);    
        s1 = new JLabel("输入密码：");
        s2 = new JLabel("显示密码：");
        s3 = new JLabel("密码添加："); 
        add();
        set();
        event();      		
	}
	void add(){
        cp.add(s1);
        cp.add(pwdIn);
        cp.add(s2);
        cp.add(pwdOut);
        cp.add(s3);
        cp.add(pwdShow);
	}
	void set(){
        f.setLayout(l);
        pwdIn.setEchoChar('#');
        pwdShow.setLineWrap(true);  
        f.setSize(230, 200);
        f.setLocationRelativeTo(null);  //让窗体居中显示
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	void event(){
        pwdIn.addCaretListener(new CaretListener() {
        	public void caretUpdate(CaretEvent e){
        		String password = String.valueOf(pwdIn.getPassword());
        		//如果密码框改变内容，就即时更新文本框和编辑框中显示的内容    	
        		pwdOut.setText(password);
        		pwdShow.setText(password);
        	}
        }); 
		
	}
	public static void main(String[] args) {
		new TextsTest();
	}
}