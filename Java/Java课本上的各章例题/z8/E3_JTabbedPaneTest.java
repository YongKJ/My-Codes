package z8;
import java.awt.Dimension;
import javax.swing.*;
public class E3_JTabbedPaneTest {	
	public static void main(String[] args) {
		JFrame jf =new JFrame("JTabbedPane测试");
		JTabbedPane tp=new JTabbedPane();//创建一个选项卡容器tp
		jf.setContentPane(tp);  //将tp添加到顶层容器内		
		JPanel jp1=new JPanel();
		tp.addTab("Tab1",jp1);   //将面板jp1添加到选项卡容器  
		tp.setEnabledAt(0,true); //设置选项卡0可用
		tp.setTitleAt(0,"学校");  //设置选项卡0的标题 
		JLabel l1=new JLabel("韶关学院");
		jp1.add(l1);
		JPanel jp2=new JPanel();
		tp.addTab("Tab2",jp2);
		tp.setEnabledAt(1,true);
		tp.setTitleAt(1,"专业");
		JLabel l2=new JLabel("计算机科学与技术");
		jp2.add(l2);		 
		tp.setPreferredSize(new Dimension(200,100));//设置大小
		tp.setTabPlacement(JTabbedPane.TOP);//设置选项卡的方向
		//设置选项卡在容器内的显示形式
		tp.setTabLayoutPolicy(JTabbedPane.SCROLL_TAB_LAYOUT);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.setVisible(true);
		jf.setSize(new Dimension(200, 100)); 
	}
}