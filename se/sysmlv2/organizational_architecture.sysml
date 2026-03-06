/*
 * SysMLv2 Translation of Organizational Architecture
 * Original: Capella Operational Analysis (OA) Diagram
 * System: Rural Aqueduct Management
 */

package 'Organizational Architecture' {

    // ============================================================
    // ITEM DEFINITIONS - Exchange Items (data flowing between activities)
    // ============================================================

    item def WaterPollutionSourceData {
        attribute source : String;
        attribute pollutantType : String;
        attribute severity : ScalarValues::Real;
    }

    item def WaterLossData {
        attribute eventType : String;  // tank overflow, pipe burst
        attribute location : String;
        attribute timestamp : ScalarValues::String;
        attribute volumeLost : ScalarValues::Real;
    }

    item def ComplianceAssessmentDataFormat {
        attribute standardId : String;
        attribute metricValues : String;
    }

    item def WaterQualityData {
        attribute pH : ScalarValues::Real;
        attribute turbidity : ScalarValues::Real;
        attribute fertilizerContent : ScalarValues::Real;
    }

    item def SupplyDemandData {
        attribute tankLevel : ScalarValues::Real;
        attribute waterPressure : ScalarValues::Real;
        attribute volumeOutflow : ScalarValues::Real;
    }

    item def SupplyDemandForecast {
        attribute predictedDemand : ScalarValues::Real;
        attribute predictedSupply : ScalarValues::Real;
        attribute forecastPeriod : ScalarValues::String;
    }

    item def ShareableData {
        attribute dataPayload : String;
        attribute accessLevel : String;
    }

    item def ShareableWaterQualityData {
        attribute qualityMetrics : String;
        attribute complianceFlags : String;
    }

    item def WaterQualityComplianceStatus {
        attribute isCompliant : ScalarValues::Boolean;
        attribute violations : String;
    }

    // ============================================================
    // PART DEFINITIONS - Operational Entities (Actors/Components)
    // ============================================================

    /*
     * External Operational Actors
     * These are entities outside the Rural Aqueduct that interact with it
     */

    part def WaterLossEventDetector {
        doc /* Detects discrete water loss events (tank overflow, pipe burst) */
        port out waterLossEvents : WaterLossEventPort;
    }

    part def RealTimeRemoteMonitor {
        doc /* Provides real-time and remote monitoring capabilities */
        port out realTimeData : RealTimeDataPort;
    }

    part def WaterQualityMetricsSource {
        doc /* Provides metrics including pH, turbidity, fertilizer content */
        port out qualityMetrics : QualityMetricsPort;
    }

    part def SupplyDemandMetricsSource {
        doc /* Provides metrics including tank level, water pressure, volume outflow */
        port out sdMetrics : SDMetricsPort;
    }

    /*
     * Internal Operational Entity - Rural Aqueduct
     * The main system being analyzed
     */

    part def RuralAqueduct {
        doc /* Main operational entity for rural aqueduct management */

        // Ports for external interactions
        port in waterLossEventIn : WaterLossEventPort;
        port in realTimeRemoteIn : RealTimeDataPort;
        port in qualityMetricsIn : QualityMetricsPort;
        port in sdMetricsIn : SDMetricsPort;

        // Ports for internal activity exchanges
        port out pollutionSourceDataOut : PollutionDataPort;
        port out waterLossDataOut : WaterLossDataPort;
        port out complianceDataOut : ComplianceDataPort;
        port out qualityDataOut : QualityDataPort;
        port out sdDataOut : SDDataPort;
        port out sdForecastOut : SDForecastPort;

        // Ports for external data sharing
        port out shareableDataOut : ShareableDataPort;
        port out shareableQualityDataOut : ShareableQualityDataPort;
        port in complianceStatusIn : ComplianceStatusPort;

        // ============================================================
        // OPERATIONAL ACTIVITIES - Functions performed by Rural Aqueduct
        // ============================================================

        action identifyWaterPollutionSources : IdentifyWaterPollutionSources;
        action monitorWaterLoss : MonitorWaterLoss;
        action defineComplianceData : DefineComplianceDataRequirements;
        action monitorWaterQuality : MonitorWaterQuality;
        action monitorSupplyDemand : MonitorSupplyDemand;

        action implementPollutionMitigation : ImplementWaterPollutionMitigationStrategy;
        action implementLossMitigation : ImplementWaterLossMitigationStrategy;
        action sendDataToExternal : SendDataToExternalEntities;
        action implementQualityControl : ImplementWaterQualityControlStrategy;
        action implementComplianceStrategy : ImplementWaterQualityStandardsComplianceStrategy;
        action predictSupplyDemand : PredictWaterSupplyAndDemand;
        action defineDistributionRules : DefineWaterDistributionRules;
    }

    /*
     * External Data Aggregators
     */

    part def ExternalDataAggregators {
        doc /* External entity that receives and aggregates aqueduct data */
        port in shareableDataIn : ShareableDataPort;

        action receiveAqueductData : ReceiveAqueductData;
    }

    /*
     * Water Quality Standards Compliance Evaluator
     */

    part def WaterQualityComplianceEvaluator {
        doc /* External entity that assesses water quality standards compliance */
        port in qualityDataIn : ShareableQualityDataPort;
        port out complianceStatusOut : ComplianceStatusPort;

        action assessCompliance : AssessWaterQualityStandardsCompliance;
    }

    // ============================================================
    // ACTION DEFINITIONS - Operational Activities
    // ============================================================

    action def IdentifyWaterPollutionSources {
        in rawObservations : String;
        out waterPollutionSourceData : WaterPollutionSourceData;
    }

    action def MonitorWaterLoss {
        in waterLossEvents : WaterLossData;
        out waterLossData : WaterLossData;
    }

    action def DefineComplianceDataRequirements {
        doc /* Defines data required for water quality standards compliance assessment */
        in qualityStandards : String;
        out complianceAssessmentDataFormat : ComplianceAssessmentDataFormat;
    }

    action def MonitorWaterQuality {
        in rawMetrics : WaterQualityData;
        out waterQualityData : WaterQualityData;
    }

    action def MonitorSupplyDemand {
        in rawSDMetrics : SupplyDemandData;
        out sdData : SupplyDemandData;
    }

    action def ImplementWaterPollutionMitigationStrategy {
        in pollutionSourceData : WaterPollutionSourceData;
        out mitigationActions : String;
    }

    action def ImplementWaterLossMitigationStrategy {
        in waterLossData : WaterLossData;
        out mitigationActions : String;
    }

    action def SendDataToExternalEntities {
        in internalData : String;
        out shareableData : ShareableData;
    }

    action def ImplementWaterQualityControlStrategy {
        in waterQualityData : WaterQualityData;
        out controlActions : String;
    }

    action def ImplementWaterQualityStandardsComplianceStrategy {
        in complianceStatus : WaterQualityComplianceStatus;
        out complianceActions : String;
    }

    action def PredictWaterSupplyAndDemand {
        in sdData : SupplyDemandData;
        out sdForecast : SupplyDemandForecast;
    }

    action def DefineWaterDistributionRules {
        in sdForecast : SupplyDemandForecast;
        out distributionRules : String;
    }

    // External operational activities

    action def ReceiveAqueductData {
        in shareableData : ShareableData;
        out aggregatedData : String;
    }

    action def AssessWaterQualityStandardsCompliance {
        in shareableWaterQualityData : ShareableWaterQualityData;
        out complianceStatus : WaterQualityComplianceStatus;
    }

    // ============================================================
    // PORT DEFINITIONS - For typed connections
    // ============================================================

    port def WaterLossEventPort {
        out item events : WaterLossData;
    }

    port def RealTimeDataPort {
        out item data : String;
    }

    port def QualityMetricsPort {
        out item metrics : WaterQualityData;
    }

    port def SDMetricsPort {
        out item metrics : SupplyDemandData;
    }

    port def PollutionDataPort {
        in item data : WaterPollutionSourceData;
        out item data : WaterPollutionSourceData;
    }

    port def WaterLossDataPort {
        in item data : WaterLossData;
        out item data : WaterLossData;
    }

    port def ComplianceDataPort {
        in item data : ComplianceAssessmentDataFormat;
        out item data : ComplianceAssessmentDataFormat;
    }

    port def QualityDataPort {
        in item data : WaterQualityData;
        out item data : WaterQualityData;
    }

    port def SDDataPort {
        in item data : SupplyDemandData;
        out item data : SupplyDemandData;
    }

    port def SDForecastPort {
        in item forecast : SupplyDemandForecast;
        out item forecast : SupplyDemandForecast;
    }

    port def ShareableDataPort {
        in item data : ShareableData;
        out item data : ShareableData;
    }

    port def ShareableQualityDataPort {
        in item data : ShareableWaterQualityData;
        out item data : ShareableWaterQualityData;
    }

    port def ComplianceStatusPort {
        in item status : WaterQualityComplianceStatus;
        out item status : WaterQualityComplianceStatus;
    }

    // ============================================================
    // TOP-LEVEL OPERATIONAL SCENARIO - Integration of all elements
    // ============================================================

    action ruralAqueductOperations {

        // ============================================================
        // PARTS - Instances of operational entities
        // ============================================================

        part waterLossDetector : WaterLossEventDetector;
        part rtRemoteMonitor : RealTimeRemoteMonitor;
        part qualityMetrics : WaterQualityMetricsSource;
        part sdMetrics : SupplyDemandMetricsSource;

        part ruralAqueduct : RuralAqueduct;
        part dataAggregators : ExternalDataAggregators;
        part complianceEvaluator : WaterQualityComplianceEvaluator;

        // ============================================================
        // EXTERNAL CONNECTIONS - Actors to Rural Aqueduct
        // ============================================================

        /*
         * Detect discrete water loss events → Monitor water loss
         * Real-time and remote → Monitor water loss
         */
        connect waterLossDetector.waterLossEvents to ruralAqueduct.waterLossEventIn;
        connect rtRemoteMonitor.realTimeData to ruralAqueduct.realTimeRemoteIn;

        /*
         * Metrics (pH, turbidity, fertilizer) → Monitor water quality
         */
        connect qualityMetrics.qualityMetrics to ruralAqueduct.qualityMetricsIn;

        /*
         * Metrics (tank level, pressure, outflow) → Monitor water supply and demand
         */
        connect sdMetrics.sdMetrics to ruralAqueduct.sdMetricsIn;

        // ============================================================
        // INTERNAL FUNCTIONAL FLOWS - Within Rural Aqueduct
        // ============================================================

        /*
         * Identify sources of water pollution → Implement water pollution mitigation strategy
         * Flow: Water pollution source data
         */
        flow ruralAqueduct.identifyWaterPollutionSources.waterPollutionSourceData
            to ruralAqueduct.implementPollutionMitigation.pollutionSourceData;

        /*
         * Monitor water loss → Implement water loss mitigation strategy
         * Flow: Water loss data
         */
        flow ruralAqueduct.monitorWaterLoss.waterLossData
            to ruralAqueduct.implementLossMitigation.waterLossData;

        /*
         * Define data required for water quality standards compliance assessment
         *   → Send data to external entities
         * Flow: Compliance assessment data format
         */
        flow ruralAqueduct.defineComplianceData.complianceAssessmentDataFormat
            to ruralAqueduct.sendDataToExternal.internalData;

        /*
         * Monitor water quality → Implement water quality control strategy
         * Flow: Water quality data
         */
        flow ruralAqueduct.monitorWaterQuality.waterQualityData
            to ruralAqueduct.implementQualityControl.waterQualityData;

        /*
         * Monitor water supply and demand → Predict water supply and demand
         * Flow: S/D data
         */
        flow ruralAqueduct.monitorSupplyDemand.sdData
            to ruralAqueduct.predictSupplyDemand.sdData;

        /*
         * Predict water supply and demand → Define water distribution rules
         * Flow: S/D forecast
         */
        flow ruralAqueduct.predictSupplyDemand.sdForecast
            to ruralAqueduct.defineDistributionRules.sdForecast;

        // ============================================================
        // EXTERNAL FLOWS - To/From External Data Aggregators
        // ============================================================

        /*
         * Send data to external entities → Receive aqueduct data
         * Flow: Shareable data
         */
        connect ruralAqueduct.shareableDataOut to dataAggregators.shareableDataIn;

        // ============================================================
        // EXTERNAL FLOWS - To/From Water Quality Compliance Evaluator
        // ============================================================

        /*
         * Send data to external entities → Assess water quality standards compliance
         * Flow: Shareable water quality data
         */
        connect ruralAqueduct.shareableQualityDataOut to complianceEvaluator.qualityDataIn;

        /*
         * Assess water quality standards compliance → Implement water quality standards compliance strategy
         * Flow: Water quality standards compliance status
         */
        connect complianceEvaluator.complianceStatusOut to ruralAqueduct.complianceStatusIn;

        // ============================================================
        // FLOW CONNECTIONS FOR COMPLIANCE STRATEGY
        // ============================================================

        flow from complianceEvaluator.assessCompliance.complianceStatus
            to ruralAqueduct.implementComplianceStrategy.complianceStatus;

        // ============================================================
        // OPERATIONAL SCENARIO SEQUENCE (Functional Chain)
        // ============================================================

        /*
         * Primary operational flow sequence:
         * Monitoring activities happen continuously (concurrent)
         * Then mitigation strategies are implemented based on data
         */

        first ruralAqueduct.monitorWaterLoss;
        first ruralAqueduct.monitorWaterQuality;
        first ruralAqueduct.monitorSupplyDemand;
        first ruralAqueduct.identifyWaterPollutionSources;
        first ruralAqueduct.defineComplianceData;

        then ruralAqueduct.implementPollutionMitigation;
        then ruralAqueduct.implementLossMitigation;
        then ruralAqueduct.predictSupplyDemand;

        then ruralAqueduct.sendDataToExternal;
        then dataAggregators.receiveAqueductData;

        then ruralAqueduct.implementQualityControl;
        then complianceEvaluator.assessCompliance;
        then ruralAqueduct.implementComplianceStrategy;

        then ruralAqueduct.defineDistributionRules;

    }

}
