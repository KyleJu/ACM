import java.util.*;

public class c{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		final Person[] p = new Person[n];

		for (int i = 0; i < n; i++) {
			ArrayList<Integer> l = new ArrayList<Integer>();
			String name = "";
			while(sc.hasNext()) {
				String s = sc.next();
				if (s.equals("class")) break;
				if (s.equals("upper")) l.add(3);
				if (s.equals("middle")) l.add(2);
				if (s.equals("lower")) l.add(1);
				if (s.substring(s.length()-1).equals(":")) {
					name = s.substring(0,s.length()-1);
					//System.out.println(name);
				}
				//System.out.println(s);
			}
			p[i] = new Person(name, l);
		}

		Arrays.sort (p, new Comparator<Person>() {
			@Override
			public int compare(Person p1, Person p2) {	
				for (int i = 0; i < Math.max(p1.l.size(), p2.l.size()); i++) {
					int a1 = 0; int a2 = 0;
					if (p1.l.size() - 1  <i) {
						a1 = 2;
					} else {
						a1 = p1.l.get(p1.l.size() -1 -i);
					}
					if (p2.l.size() -1 < i) {
						a2 = 2;
					} else {
						a2 = p2.l.get(p2.l.size() - 1 - i);
					}
					// if it alwasy equals --> check name
					if (a1 == a2) {
						continue;
					} 
					return a1 - a2;
				}
				return p2.n.compareTo(p1.n);
			}
		});

		for (int i = n-1; i >=0; i--) {
			System.out.println(p[i].n);
		}
	}

	static class Person {
		public String n;
		public ArrayList<Integer> l;
		public Person(String n1, ArrayList<Integer> l1) {
			n = n1;
			l = l1;
		}
	}
}