using System;

namespace Problem975 {
	internal class Program {
		public static void Main(string[] args) {
			int n = int.Parse(Console.ReadLine());
			int[, ] a = new int[n, n];
			for (int i = 0; i < n; i++) {
				string setir = Console.ReadLine();
				var massiv = setir.Split(' ');
				for (int j = 0; j < n; j++) {
					a[i, j] = int.Parse(massiv[j]);
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						if (Math.Min(a[j, i], a[i, k]) != -1) {
							if (a[j, k] == -1 || a[j, k] > a[j, i] + a[i, k]) {
								a[j, k] = a[j, i] + a[i, k];
							}
						}
					}
				}
			}

			int max = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					max = Math.Max(max, a[i, j]);
				}
			}
			Console.WriteLine(max);
		}
	}
}