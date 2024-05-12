package shasta

// TableInfo provides meta data describing a DB table.
type TableInfo struct {
	ID      int64  `json:"id"`
	Name    string `json:"name"`
	Charset string `json:"charset"`
	Collate string `json:"collate"`
	// Columns are listed in the order in which they appear in the schema.
	Columns []*ColumnInfo `json:"cols"`
}

// ColumnInfo provides meta data describing of a table column.
type ColumnInfo struct {
	ID                  int64               `json:"id"`
	Name                string              `json:"name"`
	Offset              int                 `json:"offset"`
	OriginDefaultValue  interface{}         `json:"origin_default"`
	DefaultValue        interface{}         `json:"default"`
	GeneratedExprString string              `json:"generated_expr_string"`
	GeneratedStored     bool                `json:"generated_stored"`
	Dependencies        map[string]struct{} `json:"dependencies"`
}
