using AutoTestForIntegral3x.Models;

namespace AutoTestForIntegral3x.Services.Interfaces
{
    public interface IProgramProcess
    {
        string GetResultProgramProcess(InputData data);
        string GetPositiveOracleResultTest(InputData data);
        string GetNegativeOracleResultTest(InputData data);
    }
}
