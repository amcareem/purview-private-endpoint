import com.azure.resourcemanager.purview.models.PrivateLinkServiceConnectionState;
import com.azure.resourcemanager.purview.models.Status;

/** Samples for PrivateEndpointConnections CreateOrUpdate. */
public final class Main {
    /*
     * x-ms-original-file: specification/purview/resource-manager/Microsoft.Purview/stable/2021-07-01/examples/PrivateEndpointConnections_CreateOrUpdate.json
     */
    /**
     * Sample code: PrivateEndpointConnections_CreateOrUpdate.
     *
     * @param manager Entry point to PurviewManager.
     */
    public static void privateEndpointConnectionsCreateOrUpdate(
        com.azure.resourcemanager.purview.PurviewManager manager) {
        manager
            .privateEndpointConnections()
            .define("privateEndpointConnection1")
            .withExistingAccount("SampleResourceGroup", "account1")
            .withPrivateLinkServiceConnectionState(
                new PrivateLinkServiceConnectionState()
                    .withDescription("Approved by johndoe@company.com")
                    .withStatus(Status.APPROVED))
            .create();
    }
}