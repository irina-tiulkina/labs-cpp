using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using AutoTestForIntegral3x.Interfaces;
using AutoTestForIntegral3x.Models;
using AutoTestForIntegral3x.Services.Interfaces;
using DynamicData;
using ReactiveUI;

namespace AutoTestForIntegral3x.vm
{
    public class MainViewModel : ViewModelBase
    {
        #region Fields
        
        private SettingsAutoTest settings;
        private ObservableCollection<ResultTest> results;

        #endregion

        private readonly IGenerateAutoTests _generateAutoTests;
        public MainViewModel(IGenerateAutoTests generateAutoTests)
        {
            _generateAutoTests = generateAutoTests;
            

            //var scenariosPositive = new ObservableCollection<InfoTestingScenario>()
            //{
            //    new InfoTestingScenario()
            //    {
            //        TypeTest = TypeTest.PositiveVarStepAndMethod,
            //        Name = "Варьирование шага и метода \r\nинтегрирования в \r\nрегламентных диапазонах",
            //        IsInputBorder = true,
            //        IsInputMethod = false,
            //        IsInputPolinome = true,
            //        IsInputStep = false
            //    },
            //};

            //var scenariosNegative = new ObservableCollection<InfoTestingScenario>()
            //{
            //    new InfoTestingScenario()
            //    {
            //        TypeTest = TypeTest.NegativeVarStepAndMethod,
            //        Name = "Неправильный формат \r\nшага и метода \r\nинтегрирования",
            //        IsInputBorder = true,
            //        IsInputMethod = false,
            //        IsInputPolinome = true,
            //        IsInputStep = false
            //    }
            //};

            // инициализация
            Settings = new SettingsAutoTest();
            Results = new ObservableCollection<ResultTest>();
            
            StartTestsCommand = new AsyncCommand( StartTestsAsync, () => CanStartTests);
            ExportResultToReportCommand = new AsyncCommand(ExportResultToReportAsync, () => CanExportResultToReport);
            ClearResultCommand = new AsyncCommand(ClearResultAsync, () => CanClearResult);

            Settings.Input = new InputData()
            {
                LeftBoundary = "-1",
                RightBoundary = "1",
                Method = Settings.Methods[0],
                Polynome = "1 2 3 4 5",
                Step = "0,0005"
            };
            Settings.Accuracy = 0.0001;
            Settings.CountTests = 10;
            Settings.Scenario.IsPositiveTest = true;
            //Settings.Scenario = Settings.TestingScenariosPositive[0];
        }

        #region Properties

        public SettingsAutoTest Settings
        {
            get => settings;
            set
            {
                settings = value;
                OnPropertyChanged(nameof(Settings));
                //OnPropertyChanged(nameof(Input));
            }
        }

        
        public ObservableCollection<ResultTest> Results
        {
            get => results;
            set
            {
                results = value;
                OnPropertyChanged(nameof(Results));
                //this.RaiseAndSetIfChanged(ref results, value);
            }
        }

        #endregion

        #region Commands

        public AsyncCommand StartTestsCommand { get; set; }

        private bool CanStartTests => Settings.IsValidInputData();

        public AsyncCommand ExportResultToReportCommand { get; set; }

        private bool CanExportResultToReport => Results.Count > 0 && Results != null;

        public AsyncCommand ClearResultCommand { get; set; }

        private bool CanClearResult => Results.Count > 0 && Results != null;
        #endregion

        #region Methods

        private async Task StartTestsAsync()
        {
            if (!Settings.IsValidInputData())
            {
                MessageBox.Show("Некорректные входные данные!");
                return;
            }

            if (Settings.Scenario.IsPositiveTest)
            {

                var results = await _generateAutoTests.GetPositiveResultTests(Settings);
                
                Results.AddRange(results);
            }
            else
            {

                var results = await _generateAutoTests.GetNegativeResultTests(Settings);
                Results.AddRange(results);
            }
        }

        private async Task ExportResultToReportAsync()
        {

        }
        private async Task ClearResultAsync()
        {
            Results.Clear();
        }

        #endregion
    }
}
