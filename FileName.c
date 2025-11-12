/*
 * Fitness Tracker v1.0
 * Author: [Roman Mykhailiv]
 * Date: November 2024
 * Description: Console-based workout tracking application
 */



#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
struct Workout {
	char type[20];
	int time;
	char date[12];
	int calories;

};
struct Goal {

	int target1;
	int target2;
	char date_set[12];
};
void add_workout(struct Workout** ptr, int* count) {
	*ptr = (struct Workout*)realloc(*ptr, ((*count) + 1) * sizeof(struct Workout));
	printf("Enter the type of workout\n");
	scanf_s("%29s", (*ptr)[*count].type, 30);
	printf("Enter the date of workout\n");
	scanf_s("%11s", (*ptr)[*count].date, 12);
	printf("Enter time of workount(minutes)\n");
	scanf_s("%d", &(*ptr)[*count].time);
	printf("Enter amount  of calories burned\n");
	scanf_s("%d", &(*ptr)[*count].calories);
	(*count)++;

}
void show_all(struct Workout* ptr, int count) {
	if (count == 0) {
		printf("No workouts yet!\n\n");
		return;
	}
	printf("\n=== ALL WORKOUTS ===\n");
	for (int i = 0; i < count; i++) {
		printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n", i + 1, ptr[i].type, ptr[i].time, ptr[i].calories, ptr[i].date);

	}
}
void show_general_stats(struct Workout* ptr, int count) {
	if (count <= 0) {
		printf("Sorry no workouts yet\n");
		return;
	}
	int total_minutes = 0, total_calories = 0;
	for (int i = 0; i < count; i++) {
		total_minutes = total_minutes + ptr[i].time;
		total_calories = total_calories + ptr[i].calories;
	}
	printf("Total workouts:%d\n", count);
	printf("Total minutes of traning:%d\n", total_minutes);
	printf("Total calories burned:%d\n", total_calories);
	printf("Avg minutes is %.1lf\n", (double)total_minutes / count);
	printf("Avg calories burned is %.1lf\n", (double)total_calories / count);


}
void show_period_stats(struct Workout* ptr, int count) {
	if (count <= 0) {
		printf("Sorry no workouts yet\n");
		return;
	}
	char start_date[12];
	char end_date[12];
	int time_per = 0, calories_per = 0;
	int count_per = 0;
	printf("Enter the start of workouts\n");
	scanf_s("%11s", start_date, 12);
	printf("Enter the end of workouts\n");
	scanf_s("%11s", end_date, 12);
	for (int i = 0; i < count; i++) {
		if ((strcmp(start_date, ptr[i].date) <= 0) && (strcmp(end_date, ptr[i].date) >= 0)) {
			time_per = time_per + ptr[i].time;
			calories_per = calories_per + ptr[i].calories;
			count_per++;
		}
	}
	if (count_per == 0) {
		printf("No workouts during this period\n");
		return;
	}

	printf("=== STATS DURING PERIOD ===\n");
	printf("All minutes of training during period:%d\nAvg minutes of training:%.1lf\n", time_per, (double)time_per / count_per);
	printf("All calories burned  during period:%d\nAvg calories burned:%.1lf\n", calories_per, (double)calories_per / count_per);



}
void find_by_type(struct Workout* ptr, int count) {
	char search_type[30];
	int find = 0;
	printf("Enter workout to search\n");
	scanf_s("%29s", search_type, 30);
	printf("=== SEARCH RESULTS ===\n");
	for (int i = 0; i < count; i++) {
		if (strcmp(search_type, ptr[i].type) == 0) {
			printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n", i + 1, ptr[i].type, ptr[i].time, ptr[i].calories, ptr[i].date);
			find++;
		}
	}
	if (find == 0) {
		printf("Sorry no such treaning\n");

	}
}
void find_longest_workout(struct Workout* ptr, int count) {
	if (count == 0) {
		printf("No workouts yet\n");
		return;

	}
	int max_time = 0;
	for (int i = 0; i < count; i++) {
		if (max_time < ptr[i].time) {
			max_time = ptr[i].time;
		}
	}
	printf("=== LONGEST WORKOUT ===\n");
	for (int i = 0; i < count; i++) {
		if (max_time == ptr[i].time) {
			printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n", i + 1, ptr[i].type, max_time, ptr[i].calories, ptr[i].date);

		}


	}

}
void find_most_calories(struct Workout* ptr, int count) {
	if (count == 0) {
		printf("No workouts yet\n");
		return;

	}
	int max_cal = 0;
	for (int i = 0; i < count; i++) {
		if (max_cal < ptr[i].calories) {
			max_cal = ptr[i].calories;
		}
	}
	printf("=== MOST CALORIES BURNED ===\n");
	for (int i = 0; i < count; i++) {
		if (max_cal == ptr[i].calories) {
			printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n", i + 1, ptr[i].type, ptr[i].time, max_cal, ptr[i].date);
		}
	}

}
void delete_workout(struct Workout** ptr, int* count) {
	int num, ch2;
	if (*count == 0) {
		printf("No workouts to delete\n");
		return;

	}
	for (int i = 0; i < *count; i++) {
		printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n", i + 1, (*ptr)[i].type, (*ptr)[i].time, (*ptr)[i].calories, (*ptr)[i].date);

	}
	printf("Enter workout number to delete\n");
	scanf_s("%d", &num);
	int index = num - 1;
	if (index < 0 || index >= *count) {
		printf("Invalid number\n");
		return;

	}
	for (int i = 0; i < *count; i++) {
		if (i == index) {
			printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n", i + 1, (*ptr)[i].type, (*ptr)[i].time, (*ptr)[i].calories, (*ptr)[i].date);
		}

	}
	printf("Are you sure you want delete workout?1-yes 0-no\n");
	scanf_s("%d", &ch2);
	if (ch2 == 1) {
		for (int i = index; i < *count - 1; i++) {
			(*ptr)[i] = (*ptr)[i + 1];
		}

	}
	else {
		return;
	}
	(*count)--;
	*ptr = realloc(*ptr, (*count) * sizeof(struct Workout));
	printf("Workout deleted successfully\n");







}
void edit_workout(struct Workout* ptr, int count) {
	int num1;
	if (count == 0) {
		printf("No workouts to delete\n");
	}
	show_all(ptr, count);
	printf("Enter nuber to edit\n");
	scanf_s("%d", &num1);
	int index = num1 - 1;
	if (index < 0 || index >= count) {
		printf("Invalid number\n");
		return;
	}
	printf("Current workout:\n");
	printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n",
		index + 1, ptr[index].type, ptr[index].time,
		ptr[index].calories, ptr[index].date);


	int chh;
	printf("\nWhat to edit?\n");
	printf("1) Type\n");
	printf("2) Duration\n");
	printf("3) Calories\n");
	printf("4) Date\n");
	printf("0) Cancel\n");
	printf("Choose: ");
	scanf_s("%d", &chh);

	if (chh == 1) {
		printf("Enter new type: ");
		scanf_s("%29s", ptr[index].type, 30);
	}
	else if (chh == 2) {
		printf("Enter new duration: ");
		scanf_s("%d", &ptr[index].time);
	}
	else if (chh == 3) {
		printf("Enter new calories: ");
		scanf_s("%d", &ptr[index].calories);
	}
	else if (chh == 4) {
		printf("Enter new date: ");
		scanf_s("%11s", ptr[index].date, 12);
	}
	else if (chh == 0) {
		printf("Cancelled\n");
		return;
	}
	else {
		printf("Invalid choice\n");
		return;
	}
	printf("\nWorkout updated successfully!\n");
	printf("# %d | Type: %s | Duration: %d min | Calories: %d | Date: %s\n",
		index + 1, ptr[index].type, ptr[index].time,
		ptr[index].calories, ptr[index].date);
}
void set_goal(struct Goal** tmp, int* goal_n) {
	*tmp = realloc(*tmp, (*goal_n + 1) * sizeof(struct Goal));
	if (*tmp == NULL) {
		printf("Error\n");
		return;
	}
	printf("Enter your target(cal)\n");
	scanf_s("%d", &(*tmp)[*goal_n].target1);
	printf("Enter your target(min)\n");
	scanf_s("%d", &(*tmp)[*goal_n].target2);
	if ((*tmp)[*goal_n].target1 < 0 && (*tmp)[*goal_n].target2 < 0) {
		printf("Invalid target\n");
	}
	printf("Set deadline\n");
	scanf_s("%11s", (*tmp)[*goal_n].date_set, 12);
	printf("***Goal added successfully***\n");
	(*goal_n)++;


}
void show_all_goals(struct Goal* tmp, int goal_n) {
	if (goal_n == 0) {
		printf("Sorry no goals yet\n");
		return;
	}
	printf("\n=== ALL GOALS===\n");
	for (int i = 0; i < goal_n; i++) {
		printf("# %d | Target(cal): %d  |Target(min): %d | Date: %s\n", i + 1, tmp[i].target1, tmp[i].target2, tmp[i].date_set);
	}
}
void show_daily_progress(struct Goal* tmp, struct Workout* ptr, int goal_n, int count) {
	char today_date[12];
	int current_goal = 0;
	int current_goal1 = 0;
	printf("Enter interested date\n");
	scanf_s("%11s", today_date, 12);
	for (int i = 0; i < count; i++) {
		if (strcmp(today_date, ptr[i].date) == 0) {
			current_goal = current_goal + ptr[i].calories;
			current_goal1 = current_goal1 + ptr[i].time;
		}
	}
	for (int i = 0; i < goal_n; i++) {
		if (strcmp(today_date, tmp[i].date_set) > 0) {
			printf("Sorry, deadline has passed\n\n");
			continue;
		}


		if (current_goal >= tmp[i].target1) {
			printf("Goal(cal) reached successfully\n");

		}
		else {
			printf("Not achived yet(cal)\nRemainig %d\n", tmp[i].target1 - current_goal);
		}
		if (current_goal >= tmp[i].target2) {
			printf("Goal(min) reached successfully\n");

		}
		else {
			printf("Not achived yet(min)\nRemainig %d\n", tmp[i].target2 - current_goal1);
		}


	}
}
void sort_by_date(struct Workout* ptr, int count) {
	int sort;
	struct Workout temp;
	if (count < 2) {
		printf("Not enought workouts to sort\n");
		return;
	}
	printf("Sort order:\n1) Oldest first(ascending)\n2) Newest first(descending)\nChoose:");
	scanf_s("%d", &sort);
	if (sort == 1) {
		for (int i = 0; i < count - 1; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (strcmp(ptr[j].date, ptr[j + 1].date) > 0) {
					temp = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = temp;
				}

			}
		}
		printf("Workouts sorted by date\n");
	}
	else if (sort == 2) {
		for (int i = 0; i < count - 1; i++) {
			for (int j = 0; j < count - i - 1; j++) {
				if (strcmp(ptr[j].date, ptr[j + 1].date) < 0) {
					temp = ptr[j];
					ptr[j] = ptr[j + 1];
					ptr[j + 1] = temp;

				}

			}
		}
		printf("Workouts sorted by date\n");
	}

}
void save_to_file(struct Workout* ptr, struct Goal* tmp, int count, int goal_n) {

	FILE* fp;
	fp = fopen("file_fitnes1.txt", "w");
	if (fp == NULL) {
		printf("Error\n");
		return;
	}
	fprintf(fp, "%d\n", count);
	for (int i = 0; i < count; i++) {
		fprintf(fp, "%s %d %d %s\n",
			ptr[i].type,
			ptr[i].time,
			ptr[i].calories,
			ptr[i].date);

	}
	fprintf(fp, "%d\n", goal_n);
	for (int i = 0; i < goal_n; i++) {
		fprintf(fp, "%d %d %s\n",
			tmp[i].target1,
			tmp[i].target2,
			tmp[i].date_set);
	}
	printf("Data saved successfully\n");


	fclose(fp);
}
void load_data_from_file(struct Workout** ptr, int* count, struct Goal** tmp, int* goal_n) {
	FILE* fp;
	fp = fopen("file_fitnes1.txt", "r");
	if (fp == NULL) {
		printf("Error\n");
		return;

	}
	if (*ptr != NULL) {
		free(*ptr);
	}
	fscanf(fp, "%d", count);
	*ptr = (struct Workout*)malloc((*count) * sizeof(struct Workout));
	for (int i = 0; i < *count; i++) {
		fscanf(fp, "%s %d %d %s",
			(*ptr)[i].type,
			&(*ptr)[i].time,
			&(*ptr)[i].calories,
			(*ptr)[i].date);
	}
	if (*tmp != NULL) {
		free(*tmp);
	}
	fscanf(fp, "%d", goal_n);
	*tmp = (struct Goal*)malloc((*goal_n) * sizeof(struct Goal));
	for (int i = 0; i < *goal_n; i++) {
		fscanf(fp, "%d %d %s\n",
			&(*tmp)[i].target1,
			&(*tmp)[i].target2,
			(*tmp)[i].date_set);
	}
	fclose(fp);
	printf("Data loaded successfully\n");


}
int main() {
	int goal_n = 0;
	int count = 0;
	int op;
	struct Workout* ptr = NULL;
	struct Goal* tmp = NULL;
	while (1) {
		printf("\n");
		printf("========================================\n");
		printf("        FITNESS TRACKER v1.0            \n");
		printf("========================================\n");
		printf(" 1) Add workout\n");
		printf(" 2) Show all workouts\n");
		printf(" 3) Statistics\n");
		printf(" 4) Find workout\n");
		printf(" 5) Longest workout\n");
		printf(" 6) Most calories\n");
		printf(" 7) Delete workout\n");
		printf(" 8) Edit workout\n");
		printf(" 9) Goals\n");
		printf("10) Sort workouts\n");
		printf("11) Save to file\n");
		printf("12) Load from file\n");
		printf(" 0) Exit\n");
		printf("========================================\n");
		printf("Choose: ");
		scanf_s("%d", &op);
		if (op == 1) {
			add_workout(&ptr, &count);
			printf("Your workout was added sucñóssfully\n");
		}
		if (op == 2) {
			show_all(ptr, count);
		}
		if (op == 3) {
			int chhh;
			printf("You want to see stat in general?1-yes 0-no\n");
			scanf_s("%d", &chhh);
			if (chhh == 1) {
				show_general_stats(ptr, count);
			}
			else if (chhh == 0) {
				show_period_stats(ptr, count);
			}
			else {
				printf("Error\n");

			}



		}
		if (op == 4) {
			find_by_type(ptr, count);
		}
		if (op == 5) {
			find_longest_workout(ptr, count);
		}
		if (op == 6) {
			find_most_calories(ptr, count);
		}
		if (op == 7) {
			delete_workout(&ptr, &count);

		}
		if (op == 8) {
			edit_workout(ptr, count);
		}
		if (op == 9) {
			int prog;
			printf("===MENU===\n");
			printf("1)Set goal\n2)Show all goals\n3)Show daily progres\n0)Exit\n");
			scanf_s("%d", &prog);
			if (prog == 1) {
				set_goal(&tmp, &goal_n);
			}
			else if (prog == 2) {
				show_all_goals(tmp, goal_n);

			}
			else if (prog == 3) {
				show_daily_progress(tmp, ptr, goal_n, count);
			}
			else if (prog == 0) {
				printf("Exiting...\n");
				return;
			}
		}
		if (op == 10) {
			sort_by_date(ptr, count);
		}
		if (op == 11) {
			printf("To save data you need to add workout and goal\n");
			save_to_file(ptr, tmp, count, goal_n);
		}
		if (op == 12) {
			load_data_from_file(&ptr, &count, &tmp, &goal_n);
		}
		if (op == 0) {
			printf("\n");
				printf("========================================\n");
				printf("       THANK YOU FOR USING!\n");
				printf("========================================\n");
				printf("Total workouts: %d\n", count);
				printf("Total goals: %d\n", goal_n);
				printf("========================================\n");
				printf("Goodbye!\n");
				printf("========================================\n");
				free(ptr);  
				free(tmp);  
				ptr = NULL;
				tmp = NULL;
				break;
				

			
			
		}
	}
	return(0);


}
































