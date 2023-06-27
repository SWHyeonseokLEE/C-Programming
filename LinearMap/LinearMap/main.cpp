#include <stdio.h>

#define No_Calibration_Point 5

struct CalibrationData
{
	double x[No_Calibration_Point];
	double y[No_Calibration_Point];
} cal_data;

double linear_mapping(double x)
{
	double y;

	for (int i=0; i < No_Calibration_Point; i++)
	{
		double dx;
		double dy;
		double ratio;

		if (x <= cal_data.x[0])			//첫 번째 점의 x좌표보다 작을 때
		{
			i = 0;
			double dx = cal_data.x[1] - cal_data.x[0];
			double dy = cal_data.y[1] - cal_data.y[0];
			double ratio = dy / dx;

			y = ratio * (x - cal_data.x[1]) + cal_data.y[1];

			break;
		}

		else if (x > cal_data.x[i] && x <= cal_data.x[i+1])			// x좌표 값이 n개 점의 x범위 내에 있을 때
		{
			double dx = cal_data.x[i + 1] - cal_data.x[i];
			double dy = cal_data.y[i + 1] - cal_data.y[i];
			double ratio = dy / dx;

			y = ratio * (x - cal_data.x[i]) + cal_data.y[i];

			break;
		}
		
		if (x >= cal_data.x[No_Calibration_Point-1])			//(n-1) 번째 점의 x좌표보다 작을 때
		{
			i = No_Calibration_Point-1;

			double dx = cal_data.x[No_Calibration_Point - 1] - cal_data.x[No_Calibration_Point - 2];
			double dy = cal_data.y[No_Calibration_Point - 1] - cal_data.y[No_Calibration_Point - 2];
			double ratio = dy / dx;

			y = ratio * (x - cal_data.x[No_Calibration_Point - 1]) + cal_data.y[No_Calibration_Point - 1];

			break;
		}
	}

	return y;
}


int main()
{
	cal_data = {
		{0.0, 1.0, 2.0, 3.0, 4.0},  // X 범위
		{10.0, 20.0, 30.0, 40.0, 50.0}  // y 값
	};

	double y = linear_mapping(5);

	printf("return : %lf \n", y);

	return 0;
}