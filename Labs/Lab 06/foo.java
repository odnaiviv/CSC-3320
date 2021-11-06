public class foo {
	public static void main(String args[]) {
		int x = 0;
		int i = 1;
		int s;
		while (i <= 3) {
			s = i * i;
			x = s + x;
			i++;
		}
		System.out.println("x = " + x);
	}
}
