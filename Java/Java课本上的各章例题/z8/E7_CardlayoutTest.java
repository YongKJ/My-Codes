package z8;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;
public class E7_CardlayoutTest implements ActionListener{
	CardLayout card=new CardLayout();
	JFrame f;
	JPanel cardPanel;
    JPanel controlPanel;
    JButton first, last, next, previous; 
    E7_CardlayoutTest()
	{
		f=new JFrame("卡片布局测试");
		cardPanel=new JPanel();
        cardPanel.setLayout(card); //设置cardPanel面板对象为卡片布局          
	    controlPanel=new JPanel();
	    Container cp=f.getContentPane();
        cp.add(cardPanel,BorderLayout.CENTER);
        cp.add(controlPanel,BorderLayout.SOUTH);
        JLabel l1 = new JLabel(new ImageIcon("z8\\Z8_2_SGly1.gif"));
        JLabel l2 = new JLabel(new ImageIcon("z8\\Z8_7_wgGT.jpg"));
        JLabel l3 = new JLabel(new ImageIcon("z8\\Z8_7_jfGT.jpg"));
        cardPanel.add("l1",l1);
        cardPanel.add("l2",l2);
        cardPanel.add("l3",l3);
		first = new JButton("第一张");
		next = new JButton("下一张");
		previous =new JButton("上一张");
		last = new JButton("最末张");
		controlPanel.add(first);
        controlPanel.add(next);
        controlPanel.add(previous);
        controlPanel.add(last);
        first.addActionListener(this); 
		next.addActionListener(this);
		previous.addActionListener(this);
		last.addActionListener(this);        
        f.setSize(400, 300);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setLocationRelativeTo(null);
        f.setVisible(true);		
	}	
	public void actionPerformed(ActionEvent arg0) {
		String command = arg0.getActionCommand();
		if (command.equals("第一张")) card.first(cardPanel); // card.show(cardPanel,"l1");
		if (command.equals("下一张")) 	card.next(cardPanel);
		if (command.equals("上一张")) card.previous(cardPanel);
		if (command.equals("最末张")) card.last(cardPanel);		
	}
	public static void main(String[] args) {
		new E7_CardlayoutTest();
	}
}