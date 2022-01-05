#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


int main(void) {
	srandom(time(NULL));


	struct ContainerStruct {
		int id;
		int height;
		int width;
		int length;
		int volume;
	} Container[5];
	
	typedef struct ContainerStruct ContainerStruct;


	void fill_containers(ContainerStruct a[], size_t size) {
		for(int i = 0; i < size; i++) {
			a[i].id = i + 1;
			a[i].height = random() % 10 + 1;
			a[i].width = random() % 10 + 1;
			a[i].length = random() % 10 + 1;
		}
	}

	void calculate_volume(ContainerStruct a[], size_t size) {
		for(int i = 0; i < size; i++ ) {
			a[i].volume = a[i].height * a[i].width * a[i].length;
		}
	}

	void sort_containers(ContainerStruct a[], size_t size) {
		bool repeatpass;
		ContainerStruct Storage;
		while(repeatpass) {
			/* Reset repeatpass for the next time we check if it's out of
			 * order. */
			repeatpass = false;
			for(int index = 0; index < size -1; index++) {
				if(a[index].volume < a[index + 1].volume) {
					Storage = a[index];
					a[index] = a[index + 1];
					a[index + 1] = Storage;
					repeatpass = true;
				}
			}
		}
	}

	void printContainers(ContainerStruct a[], size_t size) {
		for(int i = 0; i < size; i++) {
			printf("id: %d\n", a[i].id);
			printf("height: %d\n", a[i].height);
			printf("width: %d\n", a[i].width);
			printf("length: %d\n", a[i].length);
			printf("volume: %d\n", a[i].volume);
			printf("\n");
		}
	}


	fill_containers(Container, sizeof(Container) / sizeof(*Container));
	calculate_volume(Container, sizeof(Container) / sizeof(*Container));
	sort_containers(Container, sizeof(Container) / sizeof(*Container));
	printContainers(Container, sizeof(Container) / sizeof(*Container));



	return 0;
}
