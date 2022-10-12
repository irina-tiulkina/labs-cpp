using AutoTestForIntegral3x.Models;

namespace AutoTestForIntegral3x.Services.Interfaces
{
    public interface IGenerateRandomInputData
    {
        string[] GetPositiveBoundaryValue(double max, double min);
        Method GetPositiveMethod(int[] methods);
        string GetPositivePolinome(double max, double min, int maxLenght);
        string GetPositiveStep(double max, double min);

        string[] GetNegativeBoundaryValue();

        Method GetNegativeMethod();
        string GetNegativePolinome();
        string GetNegativeStep();

    }
}
