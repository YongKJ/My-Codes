package z8;
import java.awt.*;
import javax.swing.*;
public class E6_BorderLayoutTest {
	JFrame f = null; 
	BorderLayout l;
	public E6_BorderLayoutTest(){
		f = new JFrame("BorderLayout测试"); 
		Container cp = f.getContentPane();//获得放置组件的容器对象  
        l=new BorderLayout(5,5); //生成边界布局，组件间横向、纵向间距均为5像素
        f.setLayout(l);  
        cp.add("East",  new JButton("东（EAST）"));
        cp.add("North", new JButton("北（NORTH）"));
        cp.add("West",  new JButton("西（WEST）"));
        cp.add("South", new JButton("南（SOUTH）"));
        cp.add("Center",new JButton("中（CENTER）"));
        f.pack();
        f.setLocationRelativeTo(null);  //让窗体居中显示
        f.setVisible(true);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    } 	
	public static void main(String[] args) {
		new E6_BorderLayoutTest();
	}
}