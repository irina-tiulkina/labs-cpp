using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using AutoTestForIntegral3x.Interfaces;
using AutoTestForIntegral3x.Models;
using AutoTestForIntegral3x.Properties;
using AutoTestForIntegral3x.Services.Interfaces;

namespace AutoTestForIntegral3x.Services
{
    internal class GenerateAutoTests : IGenerateAutoTests
    {

        private readonly IGenerateRandomInputData _generateRandomInputData;
        private readonly IProgramProcess _programProcess;
        public GenerateAutoTests(IGenerateRandomInputData generateRandomInputData, IProgramProcess programProcess)
        {
            _generateRandomInputData = generateRandomInputData;
            _programProcess = programProcess;
        }

        public async Task<ICollection<ResultTest>> GetNegativeResultTests(SettingsAutoTest settings)
        {
            if (!settings.IsValidInputData() || settings.Scenario.IsPositiveTest)
            {
                return new List<ResultTest>();
            }

            // Сформировать входные данные
            var inputDatas = FormedNegativeInputData(settings.Scenario, settings.Input, settings.CountTests);
            ICollection<ResultTest> results = new List<ResultTest>();
            int num = 0;
            foreach (var data in inputDatas)
            {
                // расчет факт результата из консоли
                var resultProgramm = _programProcess.GetResultProgramProcess(data);

                // Расчитать ождаемый результат с помощью оракла
                var resultOracle = _programProcess.GetNegativeOracleResultTest(data);

                ResultTest result = FormedResultTest(num,data, settings, resultProgramm, resultOracle);
                results.Add(result);
                num++;
            }

            return results;
        }

        public async Task<ICollection<ResultTest>> GetPositiveResultTests(SettingsAutoTest settings)
        {
            if (!settings.IsValidInputData() || !settings.Scenario.IsPositiveTest)
            {
                return new List<ResultTest>();
            }

            // Сформировать входные данные
            var inputDatas = FormedPositiveInputData(settings.Scenario, settings.Input, settings.CountTests);

            ICollection<ResultTest> results = new List<ResultTest>();

            // Цикл
            int num = 1;
            foreach (var data in inputDatas)
            {
                // расчет факт результата из консоли
                var resultProgramm = _programProcess.GetResultProgramProcess(data);

                // Расчитать ождаемый результат с помощью оракла
                var resultOracle = _programProcess.GetPositiveOracleResultTest(data);

                ResultTest result = FormedResultTest(num, data, settings, resultProgramm, resultOracle);
                results.Add(result);
                num++;
            }

            return results;
        }

        private ResultTest FormedResultTest(int i, InputData dataX, SettingsAutoTest settings, string factResult, string planResult)
        {
            ResultTest result = new ResultTest();
            result.Num = i;
            result.InputDate = dataX.ToString();
            result.TypeTest = settings.Scenario.IsPositiveTest ? "П" : "Н";
            result.PlanResult = planResult;
            result.FactResult = factResult;
            if (settings.Scenario.IsPositiveTest)
            {
                if (double.TryParse(planResult, out double planD) && double.TryParse(factResult, out double factD))
                {
                    result.Conculation = Math.Abs(planD - factD) <= settings.Accuracy
                        ? "Тест пройден"
                        : "Тест не пройден";
                }
                else
                {
                    result.Conculation = planResult == factResult
                        ? "Тест пройден"
                        : "Тест не пройден";
                }
            }
            else
            {
                result.Conculation = planResult == factResult
                    ? "Тест пройден"
                    : "Тест не пройден";
            }

            return result;
        }

        private IEnumerable<InputData> FormedPositiveInputData(InfoTestingScenario scenario, InputData baseInputData, int countData)
        {
            var inputDatas = new List<InputData>();

            for (int i=0; i < countData; i++)
            {
                var data = new InputData()
                {
                    LeftBoundary = baseInputData.LeftBoundary,
                    RightBoundary = baseInputData.RightBoundary,
                    Method = baseInputData.Method,
                    Polynome = baseInputData.Polynome,
                    Step = baseInputData.Step,
                };

                if (!scenario.IsInputBorder)
                {
                    var boundary = _generateRandomInputData
                        .GetPositiveBoundaryValue(InputData.MaxBoundary, InputData.MinBoundary);
                    data.LeftBoundary = boundary[0];
                    data.RightBoundary = boundary[1];
                }
                if (!scenario.IsInputMethod)
                {
                    data.Method = _generateRandomInputData.GetPositiveMethod(InputData.ValidMethods);
                }

                if (!scenario.IsInputPolinome)
                {
                    data.Polynome = _generateRandomInputData.GetPositivePolinome(InputData.MaxCoeff, InputData.MinCoeff, InputData.MaxLenghtPolynome);
                }

                if (!scenario.IsInputStep)
                {
                    data.Step = _generateRandomInputData.GetPositiveStep(InputData.MaxStep, InputData.MinStep);
                }

                inputDatas.Add(data);
            }

            return inputDatas;
        }

        private IEnumerable<InputData> FormedNegativeInputData(InfoTestingScenario scenario, InputData baseInputData, int countData)
        {
            var inputDatas = new List<InputData>();

            for (int i = 0; i < countData; i++)
            {
                var data = new InputData()
                {
                    LeftBoundary = baseInputData.LeftBoundary,
                    RightBoundary = baseInputData.RightBoundary,
                    Method = baseInputData.Method,
                    Polynome = baseInputData.Polynome,
                    Step = baseInputData.Step,
                };

                if (!scenario.IsInputBorder)
                {
                    var boundary = _generateRandomInputData.GetNegativeBoundaryValue();
                    data.LeftBoundary = boundary[0];
                    data.RightBoundary = boundary[1];
                }
                if (!scenario.IsInputMethod)
                {
                    data.Method = _generateRandomInputData.GetNegativeMethod();
                }

                if (!scenario.IsInputPolinome)
                {
                    data.Polynome = _generateRandomInputData.GetNegativePolinome();
                }

                if (!scenario.IsInputStep)
                {
                    data.Step = _generateRandomInputData.GetNegativeStep();
                }

                inputDatas.Add(data);
            }

            return inputDatas;
        }
    }
}
