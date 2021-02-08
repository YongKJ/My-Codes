package z8;
import java.awt.*;
import javax.swing.*;
public class E2_JScrollPaneTest {
	JScrollPane sp;
	public E2_JScrollPaneTest() {
		JFrame jf = new JFrame("滚动面板JScrollPane测试");
		Container contentPane = jf.getContentPane();
		JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout(1,1));
        p1.setBorder(BorderFactory.createTitledBorder("韶关旅游图"));
		sp = new JScrollPane(p1);
        contentPane.add(sp, BorderLayout.CENTER);
		JLabel l1 = new JLabel(new ImageIcon("z8\\Z8_2_SGly1.gif"));
		p1.add(l1);		
		jf.setSize(new Dimension(400, 300));        
		jf.setVisible(true);;
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//用户点击窗口关闭  
	}
	public static void main(String[] args) {
		new E2_JScrollPaneTest();
	}
}