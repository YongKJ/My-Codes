import java.awt.Container;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.tree.DefaultMutableTreeNode;
public class TreeTest implements TreeSelectionListener{
	JFrame f;
	Container cp;
	JScrollPane treeView;
	JScrollPane scrollpane;
	JSplitPane splitpane;
	final JTree tree;
	DefaultMutableTreeNode top;
	DefaultMutableTreeNode node1,node2,tempNode;
	JTextArea text=new JTextArea(10,10);
	TreeTest(){
		f = new JFrame ("Tree测试");
		top =new DefaultMutableTreeNode("韶关大学"); 	
		node1 = new DefaultMutableTreeNode("信息科学与工程学院");			
		node2 = new DefaultMutableTreeNode("英东生物工程学院");
		tree = new JTree(top);		
		treeView = new JScrollPane(tree);
		scrollpane=new JScrollPane(text);
		splitpane=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,true,treeView,scrollpane); //分割面版	
		add();
		set();
		event();
	}
	void add(){
		cp = f.getContentPane();
		cp.add(splitpane);
		tempNode =new DefaultMutableTreeNode("计算机科学与技术");
		node1.add(tempNode);
		tempNode =new DefaultMutableTreeNode("通信工程");
		node1.add(tempNode);
		tempNode =new DefaultMutableTreeNode("信息管理与信息系统");
		node1.add(tempNode);
		tempNode =new DefaultMutableTreeNode("生物技术");
		node2.add(tempNode);
		tempNode =new DefaultMutableTreeNode("食品科学与工程");
		node2.add(tempNode);	
		top.add(node1);	
		top.add(node2);	
	}
	void set(){
		splitpane.setDividerLocation(200);     //设置splitpane的分隔线位置
		splitpane.setOneTouchExpandable(true); //设置splitpane可以展开或收起	
		f.setSize(420,200);
		f.setVisible(true);	
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	void event(){
		tree.addTreeSelectionListener(this);
	}
	public static void main(String[] args) {
		new TreeTest();
	}	
	public void valueChanged(TreeSelectionEvent e) {
		if(e.getSource()==tree) 
        { 
			DefaultMutableTreeNode node = (DefaultMutableTreeNode) tree.getLastSelectedPathComponent();
			if (node == null) return;
			if (node.isLeaf()) {
				Object object = node.getUserObject();
				text.setText("你选择了：" + object.toString()); 
			}
        }				
	}
}