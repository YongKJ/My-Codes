package z6;
public class E3_ArrayTraversal {
	public static void main(String[] args) {
		String[][] s = new String[3][];
		s[0] = new String[] { "A" };
		s[1] = new String[] { "B", "C" };
		s[2] = new String[] { "D", "E", "F" };
		for (int i = 0; i < s.length; i++) {
			for (int j = 0; j < s[i].length; j++) {
				System.out.println("s["+i+"]["+j+"]："+s[i][j]);
			}
		}
	}
}