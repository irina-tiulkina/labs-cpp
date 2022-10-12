using System;
using AutoTestForIntegral3x.Interfaces;
using AutoTestForIntegral3x.Models;
using AutoTestForIntegral3x.Services.Interfaces;

namespace AutoTestForIntegral3x.Services
{
    internal class ProgramProcess : IProgramProcess
    {
        public string GetResultProgramProcess(InputData data)
        {
            return "FakeMethod";
            throw new NotImplementedException();
        }

        public string GetPositiveOracleResultTest(InputData data)
        {
            return "FakeMethod";
        }

        public string GetNegativeOracleResultTest(InputData data)
        {
            return "FakeMethod";
        }
    }
}