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
        private InputData input;
        private SettingsAutoTest settings;
        private ObservableCollection<ResultTest> results;
        private ObservableCollection<Method> methods;
        private string unvalidMethod;
        private AsyncCommand _startTestsCommand;
        private AsyncCommand _exportResultToReportCommand;
        private AsyncCommand _clearResultCommand;

        #endregion

        public MainViewModel()
        {
            Methods = new ObservableCollection<Method>()
            {
                new Method() {Name = "Метод парабол", Value = "1"},
                new Method() { Name = "Метод трапеций", Value = "2"},
                new Method() { Name = "Метод Монте-Карло", Value = "3" }
            };

            Settings = new SettingsAutoTest()
            {
                Accuracy = 0.0001,
                CountTests = 10,
                IsFixStep = false,
                IsPositiveTests = true,
                IsUnvalidMethod = false
            };

            Input = new InputData()
            {
                LeftBoundary = "-1",
                RightBoundary = "1",
                Method = Methods[1],
                Polynome = "1 2 3 4 5",
                Step = "0,0005"
            };

            Results = new ObservableCollection<ResultTest>();
            
            StartTestsCommand = new AsyncCommand( StartTestsAsync, () => CanStartTests);
            ExportResultToReportCommand = new AsyncCommand(ExportResultToReportAsync, () => CanExportResultToReport);
            ClearResultCommand = new AsyncCommand(ClearResultAsync, () => CanClearResult);
        }

        #region Properties

        public string UnvalidMethod
        {
            get => unvalidMethod;
            set
            {
                unvalidMethod = value;
                OnPropertyChanged();
                Input.Method = new Method() {Name = "", Value = unvalidMethod};
            }
        }

        public ObservableCollection<Method> Methods
        {
            get => methods;
            set
            {
                methods = value;
                OnPropertyChanged();
            }
        }

        public SettingsAutoTest Settings
        {
            get => settings;
            set
            {
                settings = value;
                OnPropertyChanged(nameof(Settings));
            }
        }

        public InputData Input
        {
            get => input;
            set
            {
                input = value;
                OnPropertyChanged(nameof(Input));
                //this.RaiseAndSetIfChanged(ref input, value);
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

        public AsyncCommand StartTestsCommand
        {
            get => _startTestsCommand;
            set => _startTestsCommand = value;
        }

        private bool CanStartTests => (Settings.CountTests > 0)
                                      && ((Settings.IsFixStep && !string.IsNullOrEmpty(Input.Step)) ||
                                          !Settings.IsFixStep)
                                      && Settings.Accuracy > 0.000001
                                      && Settings.Accuracy < 1
                                      && !string.IsNullOrEmpty(Input.LeftBoundary)
                                      && !string.IsNullOrEmpty(Input.RightBoundary)
                                      && !string.IsNullOrEmpty(Input.Polynome)
                                      && Input.Method != null;

        public AsyncCommand ExportResultToReportCommand
        {
            get => _exportResultToReportCommand;
            set => _exportResultToReportCommand = value;
        }

        private bool CanExportResultToReport => Results.Count > 0 && Results != null;

        public AsyncCommand ClearResultCommand
        {
            get => _clearResultCommand;
            set => _clearResultCommand = value;
        }

        private bool CanClearResult => Results.Count > 0 && Results != null;
        #endregion

        #region Methods

        private async Task StartTestsAsync()
        {

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
