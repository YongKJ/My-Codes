package z9;
import java.awt.Container;
import java.awt.event.*;
import javax.swing.*;
public class E2_ClickEventTest {
	JFrame f;
	JButton btn;
	E2_ClickEventTest(){
		f=new JFrame("动作事件测试");
		Container cp = f.getContentPane();
		btn=new  JButton("单击我呀");
        cp.add("Center",btn);
        ButtonListener listen=new ButtonListener();//生成监听器
        btn.addActionListener(listen); //按钮注册监听器
        f.setSize(200,100);
		f.setVisible(true);	
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}	
	public static void main(String[] args) {
		new E2_ClickEventTest();
	}
}
class ButtonListener implements ActionListener 
{ 
     //事件处理方法。
     public void actionPerformed(ActionEvent  e)
     {       JButton  source=(JButton)e.getSource();
             source.setText("我被单击了");
     }
}