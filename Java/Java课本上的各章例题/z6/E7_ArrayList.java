package z6;
import java.util.ArrayList;
public class E7_ArrayList {
	public static void main(String[] args) {
		ArrayList<String> teamList = new ArrayList<String>();
		teamList.add("Happy lamb");
		teamList.add("Slowly lamb");
		for (int i = 0; i < teamList.size(); i++) {
			System.out.println(teamList.get(i));
		}
		for (Object obj : teamList) {
			System.out.println(obj.toString());
		}
	}
}