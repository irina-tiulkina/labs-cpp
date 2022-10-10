using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using AutoTestForIntegral3x.Models;
using ReactiveUI;

namespace AutoTestForIntegral3x.vm
{
    public class MainViewModel : ViewModelBase
    {
        #region Fields
        
        private SettingsAutoTest settings;
        private ObservableCollection<ResultTest> results;
        private string unvalidMethod;

        #endregion

        public MainViewModel()
        {
            var methods = new ObservableCollection<Method>()
            {
                new Method() { Name = "Метод парабол", Value = "1" },
                new Method() { Name = "Метод трапеций", Value = "2" },
                new Method() { Name = "Метод Монте-Карло", Value = "3" }
            };

            var testingScenarios = new ObservableCollection<InfoTestingScenario>()
            {
                new InfoTestingScenario()
                {
                    Name = "Варьирование шага и метода \r\nинтегрирования в \r\nрегламентных диапазонах",
                    IsInputBorder = true,
                    IsInputMethod = false,
                    IsInputPolinome = true,
                    IsInputStep = false
                },
                new InfoTestingScenario()
                {
                    Name = "Неправильный формат \r\nшага и метода \r\nинтегрирования",
                    IsInputBorder = true,
                    IsInputMethod = false,
                    IsInputPolinome = true,
                    IsInputStep = false
                }
            };

            // инициализация
            Settings = new SettingsAutoTest(methods, testingScenarios);
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
            Settings.IsPositiveTests = true;
            Settings.Scenario = Settings.TestingScenarios[0];
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

        // todo: Исправить условия
        private bool CanStartTests => (Settings.CountTests > 0)
                                      && Settings.Input != null
                                      && Settings.Accuracy > 0.000001
                                      && Settings.Accuracy < 1
                                      && !string.IsNullOrEmpty(Settings.Input.LeftBoundary)
                                      && !string.IsNullOrEmpty(Settings.Input.RightBoundary)
                                      && !string.IsNullOrEmpty(Settings.Input.Polynome)
                                      && Settings.Input.Method != null
                                      && !string.IsNullOrEmpty(Settings.Input.Method.Value) ;

        public AsyncCommand ExportResultToReportCommand { get; set; }

        private bool CanExportResultToReport => Results.Count > 0 && Results != null;

        public AsyncCommand ClearResultCommand { get; set; }

        private bool CanClearResult => Results.Count > 0 && Results != null;
        #endregion

        #region Methods

        private async Task StartTestsAsync()
        {
            // todo: исправить условия !!!!
            if (Settings.CountTests < 0 
                || Settings.Accuracy < 0
                || Settings.Accuracy > 1
                || Settings.Input == null
                || string.IsNullOrEmpty(Settings.Input.LeftBoundary)
                || string.IsNullOrEmpty(Settings.Input.RightBoundary)
                || string.IsNullOrEmpty(Settings.Input.Polynome)
                || Settings.Input.Method == null
                || string.IsNullOrEmpty(Settings.Input.Method.Value))
            {
                return;
            }

            if (Settings.IsPositiveTests)
            {
                
            }
            else
            {

            }
        }

        private async Task ExportResultToReportAsync()
        {

        }
        private async Task ClearResultAsync()
        {

        }
        #endregion
    }
}
