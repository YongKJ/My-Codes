package z9;
import java.awt.event.*;
import javax.swing.*;
public class Z9_4_MouseAdapterTest{//extends MouseAdapter{
	JFrame f;
	static JButton b1;
	Z9_4_MouseAdapterTest(){
		f = new JFrame("鼠标适配器测试");
		b1 = new JButton("按我呀");	
		f.add(b1);
		f.setSize(200, 100);		
		f.setLocationRelativeTo(null);//让窗体居中显示
		f.setVisible(true);
		b1.addMouseListener(new OutMouseAdapter());//1)外部类作为事件监听器		
		//b1.addMouseListener(new InMouseAdapter());//2)内部类作为事件监听器
		//b1.addMouseListener(this);//3)自身类作为事件监听器		
		/*b1.addMouseListener(new MouseAdapter(){//4)匿名内部类作为事件监听器
	        public void mousePressed(MouseEvent event)//鼠标按下事件
	        {
	        	b1.setText("我被Mouse按下了");
	        }});*/		
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	/*/3)自身类作为事件监听器
	public void mousePressed(MouseEvent event)
    {
		b1.setText("我被Mouse按下了");
    }*/
	/*/2)内部类作为事件监听器
	class InMouseAdapter extends MouseAdapter{
		public void mousePressed(MouseEvent event)
	    {
			b1.setText("我被Mouse按下了");
	    }
	}*/	
	public static void main(String[] args) {
		new Z9_4_MouseAdapterTest();
	}
}
//1)外部类作为事件监听器
class OutMouseAdapter extends MouseAdapter{
	public void mousePressed(MouseEvent event)
    {
		Z9_4_MouseAdapterTest.b1.setText("我被Mouse按下了");
    }
}