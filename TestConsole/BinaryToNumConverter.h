#pragma once
#include <stdio.h>

int main() {

	// 1.5005

	// リトルエンディアン
	char unsigned little[] = {
		0x62, 0x10, 0xC0, 0x3F,
		0x6F, 0x12, 0x83, 0x3F,
		0x62, 0x10, 0xC0, 0x3F,
		0x6F, 0x12, 0x83, 0x3F,
		0x62, 0x10, 0xC0, 0x3F,
		0x6F, 0x12, 0x83, 0x3F,
		0x62, 0x10, 0xC0, 0x3F,
		0x6F, 0x12, 0x83, 0x3F,
		0x62, 0x10, 0xC0, 0x3F,
		0x6F, 0x12, 0x83, 0x3F,
	};

	// ビッグエンディアン
	char unsigned big[] = { 0x3F, 0xC0, 0x10, 0x62, 0x3F, 0x83, 0x12, 0x6F };

	union UnionNum32 {
		int int_;
		float float_;
		char unsigned byte_[4];
		void SetByte(char unsigned * buf, int & i, bool is_little_endian) {
			if (is_little_endian) {
				byte_[0] = buf[i++];
				byte_[1] = buf[i++];
				byte_[2] = buf[i++];
				byte_[3] = buf[i++];
			}
			else {
				byte_[3] = buf[i++];
				byte_[2] = buf[i++];
				byte_[1] = buf[i++];
				byte_[0] = buf[i++];
			}
		}
	};

	int num_enemy = 5;
	int num_param = 2;
	UnionNum32 * u_val = new UnionNum32[num_param];

	int buf_cnt = 0;
	for (int i = 0; i < num_enemy; i++) {
		u_val[0].SetByte(little, buf_cnt, true);
		u_val[1].SetByte(little, buf_cnt, true);
		float param1 = u_val[0].float_;
		int param2 = u_val[1].int_;
		printf("%f\n", param1);
		printf("%d\n", param2);
		printf("\n");
	}
	printf("%d\n", buf_cnt);

	delete[] u_val;
	return 0;
}