#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>

using namespace std;

class item {
public:
	string name;
	float value;
	float weight;

	item() :value(0), weight(0) {}
	item(const string &s, const float &v, const float &w)
		:name(s), value(v), weight(w) {}
};

const float MAX_SIZE = 20.0;

int main() {

	item pack[5];
	int spForPack = 0;
	string n;
	float v;
	float w;

	float totalWeight = 0.0;

	for (int r0 = 0; r0 < 5; ++r0) {
		cin >> n >> v >> w;

		const item newItem(n, v, w);

		if ((totalWeight + newItem.weight) > MAX_SIZE) {
			item ground[5];
			int spForGround = 0;

			spForPack -= 1;

			while (spForPack >= 0) {
				const item itemHasHand = pack[spForPack--];
				const float weightOfRemove = totalWeight - itemHasHand.weight;

				if (
					(newItem.value > itemHasHand.value) &&
					((weightOfRemove + newItem.weight) <= MAX_SIZE)
					) {

					// put back
					spForPack += 1;
					spForGround -= 1;
					while (spForGround >= 0) {
						pack[spForPack++] = ground[spForGround--];
					}

					pack[spForPack++] = newItem;

					totalWeight = 0;
					for (int r0 = 0; r0 < spForPack; ++r0) {
						totalWeight += pack[r0].weight;
					}

					break;
				}
				else {
					ground[spForGround++] = itemHasHand;
				}
			}

			// put back
			if (spForGround > 0) {
				// reset sp
				spForPack += 1;
				spForGround -= 1;
				while (spForGround >= 0) {
					pack[spForPack++] = ground[spForGround--];
				}
			}
		}
		else {
			// put new item to pack
			pack[spForPack++] = newItem;
			totalWeight += newItem.weight;
		}
	}

	float totalValue = 0;
	spForPack -= 1;

	while (spForPack >= 0) {

		cout << pack[spForPack].name << " "
			<< pack[spForPack].value << " "
			<< pack[spForPack].weight << endl;

		printf(
			"%s %0.1f %0.1f\n",
			pack[spForPack].name,
			pack[spForPack].value,
			pack[spForPack].weight
		);

		totalValue += pack[spForPack].value;
		--spForPack;
	}

	printf("weight:%0.1f\n", totalWeight);
	printf("value:%0.1f\n", totalValue);

	system("pause");
}